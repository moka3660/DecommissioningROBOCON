#include<Wire.h>
#include<VL53L0X.h>

//I2Cレーザ測距
VL53L0X laser;  //
VL53L0X sencer;

void setup()
{
  Wire.begin();

  pinMode(6,OUTPUT);

  digitalWrite(6,LOW);
  laser.init();
  laser.setTimeout(500);
  laser.setAddress(21);
  laser.startContinuous();
  digitalWrite(6,HIGH);
  sencer.init();
  sencer.setTimeout(500);
  sencer.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
//  digitalWrite(6,HIGH);
  Serial.print("laser---Laser[mm]---");
  Serial.print(laser.readRangeContinuousMillimeters());
  Serial.print("---Address----");
  Serial.print(laser.getAddress());

//  Serial.println();

//  delay(500);

//  digitalWrite(6,LOW);
  Serial.print("sencer---Laser[mm]---");
  Serial.print(sencer.readRangeContinuousMillimeters());
  Serial.print("---Address----");
  Serial.print(sencer.getAddress());

  Serial.println();

  delay(500);
}
