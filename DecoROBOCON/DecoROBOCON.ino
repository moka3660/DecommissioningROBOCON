#include<Servo.h>
Servo Aileron;
Servo Elevator;
Servo Throttle;
Servo Ladder;
//プロポからの入力ピン
const int R1 = 12;  //エルロン
const int R2 = 14;  //エレベーター
const int R3 = 27;  //スロットル
const int R4 = 26;  //ラダー
//プロポからの入力用変数
int rcv[] = {0, 0, 0, 0};
//フラコンへの出力ピン
const int Pin_ail = 9;
const int Pin_ele = 13;
const int Pin_thr = 11;
const int Pin_lad = 10;
//フラコンへの出力用変数
int snd[] = {1520, 1520, 1109, 1520};


void setup()
{
  pinMode(R1,INPUT);
  pinMode(R2,INPUT);
  pinMode(R3,INPUT);
  pinMode(R4,INPUT);

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
  rcv[0] = pulseIn(R1, HIGH);
  rcv[1] = pulseIn(R2, HIGH);
  rcv[2] = pulseIn(R3, HIGH);
  rcv[3] = pulseIn(R4, HIGH);
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
