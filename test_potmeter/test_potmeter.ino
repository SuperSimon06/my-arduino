// #include <Servo.h>

// Servo servootje;

// const int servoaansturing = 3;
const int potmeter = A0;
void setup() {
  // put your setup code here, to run once:
  // pinMode (servoaansturing, OUTPUT);
  pinMode (potmeter, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potmetergetal = analogRead (potmeter);
  Serial.print("potmeter = ");
  Serial.println(potmetergetal);
  // int servograden = map (potmetergetal, 0, 1023, 0, 179);
  // Serial.print("servograden = ");
  // Serial.println(servograden);
  // servootje.write(servograden);
  delay(1000);
}
