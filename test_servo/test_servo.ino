#include <Servo.h>

Servo servootje;

const int servoaansturing = 3;
int servograden = 90;
int stapje = 10;
void setup() {
  pinMode (servoaansturing, OUTPUT);
  servootje.attach(servoaansturing);
  Serial.begin(9600);
}

void loop() {
  // Serial.print("servograden = ");
  servograden = servograden + stapje;
  if (servograden > 150 || servograden < 30) 
      stapje = stapje * -1;
  Serial.println(servograden);
  servootje.write(servograden);
  delay(1000);
}
