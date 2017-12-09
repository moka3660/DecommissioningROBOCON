#include<Wire.h>
#include<VL53L0X.h>

//I2Cレーザ測距
VL53L0X ahead;  //前方

void setup()
{
  Wire.begin();

  ahead.init();
  ahead.setTimeout(500);
  ahead.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{

  Serial.print("---Laser---___ahead:");
  Serial.print(ahead.readRangeContinuousMillimeters());

  Serial.println();

  //delay(500);
}
