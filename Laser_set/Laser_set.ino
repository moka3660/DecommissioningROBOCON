#include<Wire.h>
#include<VL53L0X.h>

//I2Cレーザ測距
VL53L0X laser;  //

void setup()
{
  Wire.begin();

  laser.init();
  laser.setTimeout(500);
  laser.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{

  Serial.print("---Laser---");
  Serial.print(laser.readRangeContinuousMillimeters());

  Serial.println();

  //delay(500);
}
