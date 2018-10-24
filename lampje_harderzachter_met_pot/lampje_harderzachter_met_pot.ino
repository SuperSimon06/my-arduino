const int lampjevoeding = 11;
const int potmeter = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode (lampjevoeding, OUTPUT);
  pinMode (potmeter, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potmetergetal = analogRead (potmeter);
  int lampjesterkte = map (potmetergetal, 0, 1023, 0, 225);
  digitalWrite (lampjevoeding, lampjesterkte);
}
