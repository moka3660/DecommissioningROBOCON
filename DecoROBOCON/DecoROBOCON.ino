//プロポからの入力ピン
const int R1 = 12;
const int R2 = 14;
const int R3 = 27;
const int R4 = 26;
//プロポからの入力用変数
int rcv[] = {0, 0, 0, 0};

void setup()
{
  pinMode(R1,INPUT);
  pinMode(R2,INPUT);
  pinMode(R3,INPUT);
  pinMode(R4,INPUT);

  Serial.begin(9600); //シリアルモニタで確認
  Serial.println("started");
}

void loop()
{
  rcv[0] = pulseIn(R1, HIGH);
  rcv[1] = pulseIn(R2, HIGH);
  rcv[2] = pulseIn(R3, HIGH);
  rcv[3] = pulseIn(R4, HIGH);

  Serial.print("___rcv[0]:");
  Serial.print(rcv[0]);
  Serial.print("___rcv[1]:");
  Serial.print(rcv[1]);
  Serial.print("___rcv[2]:");
  Serial.print(rcv[2]);
  Serial.print("___rcv[3]:");
  Serial.println(rcv[3]);

  delay(500);
}
