#include<Wire.h>
#include<VL53L0X.h>
#include<Servo.h>
Servo Aileron;
Servo Elevator;
Servo Throttle;
Servo Ladder;
//プロポからの入力ピン
const int I_ail = 2;  //エルロン
const int I_ele = 3;  //エレベーター
const int I_thr = 4;  //スロットル
const int I_lad = 5;   //ラダー
//プロポからの入力用変数
const int rcv_times = 3;//入力の平均回数
int rcv[rcv_times][4];
int rcv_ave[4]={0,0,0,0};
int rcv_count = 0;//入力平均用カウンタ
//フラコンへの出力ピン
const int O_ail = 6;
const int O_ele = 7;
const int O_thr = 8;
const int O_lad = 9;
//フラコンへの出力用変数
int snd[] = {1520, 1520, 1109, 1520};
//I2Cレーザ測距
VL53L0X ahead;  //前方

void setup()
{
  pinMode(I_ail,INPUT);
  pinMode(I_ele,INPUT);
  pinMode(I_thr,INPUT);
  pinMode(I_lad,INPUT);

  //servo.attach(pin, min, max)
  Aileron.attach(O_ail, 1109, 1930);
  Elevator.attach(O_ele, 1109, 1930);
  Throttle.attach(O_thr, 1109, 1930);
  Ladder.attach(O_lad, 1109, 1930);

  Wire.begin();

  ahead.init();
  ahead.setTimeout(500);
  ahead.startContinuous();

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
  rcv[0] = pulseIn(I_ail, HIGH);
  rcv[1] = pulseIn(I_ele, HIGH);
  rcv[2] = pulseIn(I_thr, HIGH);
  rcv[3] = pulseIn(I_lad, HIGH);

  Serial.print("___rcv[0]:");
  Serial.print(rcv[0]);
  Serial.print("___rcv[1]:");
  Serial.print(rcv[1]);
  Serial.print("___rcv[2]:");
  Serial.print(rcv[2]);
  Serial.print("___rcv[3]:");
  Serial.print(rcv[3]);

  Serial.print("---Laser---___ahead:");
  Serial.print(ahead.readRangeContinuousMillimeters());

  Serial.println();

  //delay(500);
}

void output()
{
  snd[0] = rcv_ave[0];
  snd[1] = rcv_ave[1];
  snd[2] = rcv_ave[2];
  snd[3] = rcv_ave[3];

  Aileron.writeMicroseconds(snd[0]);
  Elevator.writeMicroseconds(snd[1]);
  Throttle.writeMicroseconds(snd[2]);
  Ladder.writeMicroseconds(snd[3]);
}
