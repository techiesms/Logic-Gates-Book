#define LDR1 A0
#define LDR2 A1
#define LDR3 A2
#define But1 8
#define But2 7
#define LED 5

#define LDR_Threshold 150

bool sense1 = 0;
bool sense2 = 0;
bool sense3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(But1, INPUT);
  pinMode(But2, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  //  Serial.print("LDR1 ");
  //  Serial.println(analogRead(LDR1));
  //  Serial.print("LDR2 ");
  //  Serial.println(analogRead(LDR2));
  //  Serial.print("LDR3 ");
  //  Serial.println(analogRead(LDR3));
  if (analogRead(LDR1) > LDR_Threshold)
  {
    sense1 = 1;
  }
  else {
    sense1 = 0;
  }
  if (analogRead(LDR2) > LDR_Threshold)
  {
    sense2 = 1;
  }
  else {
    sense2 = 0;
  }
  if (analogRead(LDR3) > LDR_Threshold)
  {
    sense3 = 1;
  }
  else {
    sense3 = 0;
  }


  if (sense1 == 0 && sense2 == 0 && sense3 == 0) {
    NOT();
    Serial.println("wire");
  }
  if (sense1 == 0 && sense2 == 0 && sense3 == 1) {
    AND();
    Serial.println("NAND");
  }
  if (sense1 == 0 && sense2 == 1 && sense3 == 1) {
    NOR();
    Serial.println("OR");
  }
  if (sense1 == 1 && sense2 == 1 && sense3 == 1) {
    XNOR();
    Serial.println("XOR");
  }
  else {

  }
}


void NOT()
{
  digitalWrite(LED, !digitalRead(But1));
}

void AND()
{
  if (digitalRead(But1) == HIGH && digitalRead(But2) == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

void NOR()
{
  if (digitalRead(But1) == LOW && digitalRead(But2) == LOW)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

void XNOR()
{
  if (digitalRead(But1) == HIGH && digitalRead(But2) == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  if (digitalRead(But1) == LOW && digitalRead(But2) == LOW)
  {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
