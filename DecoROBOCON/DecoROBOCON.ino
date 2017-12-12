#include<Wire.h>
#include<VL53L0X.h>

const int LED = A1; //レーザ検知したら光らすLED
const int dis_min = 100;  //レーザ下限距離
const int dis_max = 1100; //レーザ上限距離

//I2Cレーザ測距
VL53L0X Laser;  //下方

uint16_t distance = 0;   //レーザ距離用変数

void setup()
{
  pinMode(LED,OUTPUT);
  Wire.begin();

  Laser.init();
  Laser.setTimeout(500);
  Laser.startContinuous();

  digitalWrite(LED,LOW);

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
  distance = Laser.readRangeContinuousMillimeters();
  if(dis_min <= distance && distance <= dis_max)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }

  Serial.print("---Laser---:");
  Serial.print(distance);
  Serial.print("------------");

  Serial.println();

  //delay(500);
}
