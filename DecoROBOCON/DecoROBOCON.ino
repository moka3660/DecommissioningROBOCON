#include<Servo.h>
Servo Aileron;
Servo Elevator;
Servo Throttle;
Servo Ladder;
//プロポからの入力ピン
const int Pin_ail = 12;  //エルロン
const int Pin_ele = 14;  //エレベーター
const int Pin_thr = 15;  //スロットル
const int Pin_lad = 2;   //ラダー
//プロポからの入力用変数
int rcv[] = {0, 0, 0, 0};
//フラコンへの出力ピン
const int Pout_ail = 13;
const int Pout_ele = 9;
const int Pout_thr = 10;
const int Pout_lad = 11;
//フラコンへの出力用変数
int snd[] = {1520, 1520, 1109, 1520};

void setup()
{
  pinMode(Pin_ail,INPUT);
  pinMode(Pin_ele,INPUT);
  pinMode(Pin_thr,INPUT);
  pinMode(Pin_lad,INPUT);

  //servo.attach(pin, min, max)
  Aileron.attach(Pin_ail, 1109, 1930);
  Elevator.attach(Pin_ele, 1109, 1930);
  Throttle.attach(Pin_thr, 1109, 1930);
  Ladder.attach(Pin_lad, 1109, 1930);

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
  rcv[0] = pulseIn(Pin_ail, HIGH);
  rcv[1] = pulseIn(Pin_ele, HIGH);
  rcv[2] = pulseIn(Pin_thr, HIGH);
  rcv[3] = pulseIn(Pin_lad, HIGH);
/*
  Serial.print("___rcv[0]:");
  Serial.print(rcv[0]);
  Serial.print("___rcv[1]:");
  Serial.print(rcv[1]);
  Serial.print("___rcv[2]:");
  Serial.print(rcv[2]);
  Serial.print("___rcv[3]:");
  Serial.println(rcv[3]);
*/
  snd[0] = rcv[0];
  snd[1] = rcv[1];
  snd[2] = rcv[3];
  snd[3] = rcv[3];

  Aileron.writeMicroseconds(snd[0]);
  Elevator.writeMicroseconds(snd[1]);
  Throttle.writeMicroseconds(snd[2]);
  Ladder.writeMicroseconds(snd[3]);

  //delay(500);
}
