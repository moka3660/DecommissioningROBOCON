#include<Wire.h>
#include<VL53L0X.h>

//I2Cレーザ測距
VL53L0X laser;  //

void setup()
{
  Wire.begin();

  pinMode(6,OUTPUT);

  laser.init();
  laser.setTimeout(500);
//  laser.setAddress(21);
//  laser.writeReg(0x52, 0x21);
  laser.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
  digitalWrite(6,HIGH);
  Serial.print("HIGH---Laser[mm]---");
  Serial.print(laser.readRangeContinuousMillimeters());
  Serial.print("---Address----");
  Serial.print(laser.getAddress());

  Serial.println();

  delay(500);

  digitalWrite(6,LOW);
  Serial.print("LOW---Laser[mm]---");
  Serial.print(laser.readRangeContinuousMillimeters());
  Serial.print("---Address----");
  Serial.print(laser.getAddress());

  Serial.println();

  delay(500);
}
