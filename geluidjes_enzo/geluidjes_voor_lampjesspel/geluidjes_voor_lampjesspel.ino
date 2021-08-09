const int passivebuzzer = 10;

void goedgeluid() {
  tone(passivebuzzer,440,500);
}

void foutgeluid() {
  tone(passivebuzzer,220,500);
}

void setup() {
  // put your setup code here, to run once:
    pinMode(passivebuzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  foutgeluid();
  delay(1000);
  goedgeluid();
  delay(1000);
}
