#include "I2Cdev.h"
#include "MPU6050.h"

#define TO_DEG 57.29577951308232087679815481410517033f
#define T_OUT 20
#define dima_ne_spisivay 7
int IN3 = 5; 
int IN4 = 4;
int IN2 = 6; 
int IN1 = 7;

MPU6050 accel;

float angle_ax,angle_ay, angle_az;
long int t_next;

float clamp(float v, float minv, float maxv){ // Пределы
    if( v>maxv )
        return maxv;
    else if( v<minv )
        return minv;
    return v;
}

void setup() {
    Serial.begin(9600);
    pinMode (IN4, OUTPUT);
    pinMode (IN3, OUTPUT);
    pinMode (IN2, OUTPUT);
    pinMode (IN1, OUTPUT);
    accel.initialize(); // первичная настройка датчика
}

void loop() {
  int i = 1;
    long int t = millis(); // Миллисек.
    if( t_next < t ){
        int16_t ax_raw, ay_raw, az_raw, gx_raw, gy_raw, gz_raw;
        float ay,ax,az,gx,gy,gz;

        t_next = t + T_OUT;
        accel.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);// считывает движения
 
        // сырые данные акселерометра нужно преобразовать в единицы гравитации
        // при базовых настройках 1G = 4096
        ax = ax_raw / 4096.0;
        ay = ay_raw / 4096.0;
        az = az_raw / 4096.0;
        // на случай, если на акселерометр действуют посторонние силы, которые могут
        // увеличить ускорение датчика свыше 1G, установим границы от -1G до +1G  
        ax = clamp(ax, -1.0, 1.0);
        ay = clamp(ay, -1.0, 1.0);
        az = clamp(az, -1.0, 1.0);

        // функция acos возвращает угол в радианах, так что преобразуем
        // его в градусы при помощи коэффициента TO_DEG
        if( ax >= 0){
            angle_ay = 90 - TO_DEG*acos(ax);
        } else {
            angle_ay = TO_DEG*acos(-ax) - 90;
        }

        if( ay >= 0){
            angle_ax = 90 - TO_DEG*acos(ay);
        } else {
            angle_ax = TO_DEG*acos(-ay) - 90;
        }

        if( az >= 0){
            angle_az = TO_DEG*acos(az);
        } else {
            angle_az = TO_DEG*acos(-az)*-1;
        }
        
        Serial.println(angle_ay);
        
    }
    if (angle_ay >= dima_ne_spisivay) 
    {
      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
    }
   if (angle_ay <= -dima_ne_spisivay) 
    {
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      digitalWrite (IN2, HIGH);
      digitalWrite (IN1, LOW);
    }
    if(angle_ay> -dima_ne_spisivay && angle_ay<dima_ne_spisivay)
    {
      digitalWrite (IN3, LOW);
      digitalWrite (IN4, LOW);
      digitalWrite (IN2, LOW);
      digitalWrite (IN1, LOW);
    }

}
