#include <IRremote.h>

int redPin = 6;
int greenPin = 3;
int bluePin = 9;
int RECV_PIN = 11; //define input pin on Arduino
int welkewasingedrukt = -1;
int stapgrootte = 254;

int kleur[3];

IRrecv irrecv(RECV_PIN);
decode_results results;

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
  Serial.print(kleur[0]);
  Serial.print("  ");
  Serial.print(kleur[1]);
  Serial.print("  ");
  Serial.println(kleur[2]);
}

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  kleur[0] = kleur[1] = kleur[2] = 0;
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value) {
       case 0xff30cf://1
         welkewasingedrukt = 0;
         break;
       case 0xff18e7://2
         welkewasingedrukt = 1;
         break;
       case 0xff7a85://3
         welkewasingedrukt = 2;
         break;
       case 0xff906f: // volume up
         kleur[welkewasingedrukt] += stapgrootte;
         if (kleur[welkewasingedrukt] > 255) 
           kleur[welkewasingedrukt] = 255;
         setColor(kleur[0], kleur[1], kleur[2]);
         break;
       case 0xffe01f: // volume down
         kleur[welkewasingedrukt] -= stapgrootte;
         if (kleur[welkewasingedrukt] < 0) 
           kleur[welkewasingedrukt] = 0;
         setColor(kleur[0], kleur[1], kleur[2]);
         break;
      
    }
   
    irrecv.resume(); // Receive the next value
  }
}


