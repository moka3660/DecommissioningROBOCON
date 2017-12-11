#include<Wire.h>
#include<VL53L0X.h>

//I2Cレーザ測距
VL53L0X downward;  //下方

void setup()
{
  Wire.begin();

  downward.init();
  downward.setTimeout(500);
  downward.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{

  Serial.print("---Laser---___ahead:");
  Serial.print(downward.readRangeContinuousMillimeters());

  Serial.println();

  //delay(500);
}
