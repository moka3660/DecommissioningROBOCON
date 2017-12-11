#include<Wire.h>
#include<VL53L0X.h>

const int LED = A0; //レーザ検知したら光らすLED
int distance = 0;   //レーザ距離用変数
//I2Cレーザ測距
VL53L0X laser;  //下方

void setup()
{
  pinMode(LED,OUTPUT);
  Wire.begin();

  laser.init();
  laser.setTimeout(500);
  laser.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
  distance = laser.readRangeContinuousMillimeters();

  Serial.print("---Laser---:");
  Serial.print(distance);

  Serial.println();

  //delay(500);
}
