//Arduino UNO

#include<Wire.h>
//プロポからの入力ピン
const int Pin_ail = 2;  //エルロン
const int Pin_ele = 3;  //エレベーター
const int Pin_thr = 4;  //スロットル
const int Pin_lad = 5;   //ラダー
//プロポからの入力用変数
int rcv[] = {0, 0, 0, 0};

void setup()
{
  pinMode(Pin_ail,INPUT);
  pinMode(Pin_ele,INPUT);
  pinMode(Pin_thr,INPUT);
  pinMode(Pin_lad,INPUT);

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");

  delay(1000);
}

void loop()
{
  rcv[0] = pulseIn(Pin_ail, HIGH);
  rcv[1] = pulseIn(Pin_ele, HIGH);
  rcv[2] = pulseIn(Pin_thr, HIGH);
  rcv[3] = pulseIn(Pin_lad, HIGH);

  Serial.print("___rcv[ail]:");
  Serial.print(rcv[0]);
  Serial.print("___rcv[ele]:");
  Serial.print(rcv[1]);
  Serial.print("___rcv[thr]:");
  Serial.print(rcv[2]);
  Serial.print("___rcv[lad]:");
  Serial.print(rcv[3]);

  Serial.println();

  delay(50);
}
