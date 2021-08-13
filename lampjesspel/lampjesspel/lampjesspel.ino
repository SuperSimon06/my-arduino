//#include <Time.h>
//#include <TimeLib.h>
#include <IRremote.h>

const byte IR_RECEIVE_PIN = 0;
const int lamp1 = 13;
const int lamp2 = 2;
const int lamp3 = 3;
const int lamp4 = 4;
const int lamp6 = 12;
const int lamp7 = 9; // was 6
const int lamp8 = 7;
const int lamp9 = 8;
const int rgbgroen = 5;
const int rgbrood = 6;// was 9
const int rgbblauw = 11;
const int passivebuzzer = 10;
int lamp5 = -1;
int codes[14];
#define GEEL 0
#define ROOD 1
#define GROEN 2
#define BLAUW 3
#define MAX_KLEUR 4
#define NONE 5
const byte kleuren[] = {GEEL,ROOD,GROEN,BLAUW};
byte dekleur = NONE;
byte delamp = NONE;
const byte gelelampjes[] = {lamp3,lamp9};
const byte rodelampjes[] = {lamp4,lamp8};
const byte groenelampjes[] = {lamp1,lamp6};
const byte blauwelampjes[] = {lamp2,lamp7};
const byte *allekleuren[] = {gelelampjes,rodelampjes,groenelampjes,blauwelampjes};
byte derest[6];
byte brandendelampjes[4];
byte nieuwelampnodig = 1;
int punten = 0;
unsigned long start;
int allelampjes[] = {lamp1,lamp2,lamp3,lamp4,lamp5,lamp6,lamp7,lamp8,lamp9};
int startsecond;
int endsecond;
unsigned long goedgeluideinde;
unsigned long foutgeluideinde;
unsigned long vorigsignaaltijd;

//void(* resetFunc) (void) = 0;

void brandlampjesmaker(){
  brandendelampjes[0] = delamp;
  brandendelampjes[1] = derest[random(6)];
  brandendelampjes[2] = derest[random(6)];
  brandendelampjes[3] = derest[random(6)];
}

void restmaker(const byte gekozenkleur){
  int start = 0;
  for (int kleur = GEEL; kleur < MAX_KLEUR; ++kleur) {
    if (kleur == gekozenkleur)
      continue;
    derest[start] = allekleuren[kleur][0];
    start = start + 1;
    derest[start] = allekleuren[kleur][1];
    start = start + 1;
  }
}

void lampmaker(const byte gekozenkleur){
  delamp = allekleuren[gekozenkleur][random (2)];
  Serial.println(delamp);
}

void setColor(int red, int green, int blue){
  analogWrite(rgbrood, red);
  analogWrite(rgbgroen, green);
  analogWrite(rgbblauw, blue);
}

void lampjeswisselaar(int waarde){
  for(int k = 0; k<4; ++k){
    analogWrite(brandendelampjes[k],waarde);
  }
  /*Serial.print("Lampjes op ");
  Serial.print(waarde);
  Serial.print(": ");
  Serial.print(brandendelampjes[0]);
  Serial.print(" ");
  Serial.print(brandendelampjes[1]);
  Serial.print(" ");
  Serial.print(brandendelampjes[2]);
  Serial.print(" ");
  Serial.println(brandendelampjes[3]);*/
}

void goedgeluid() {
  tone(passivebuzzer,440);
  goedgeluideinde = millis();
}

void foutgeluid() {
  tone(passivebuzzer,220);
  foutgeluideinde = millis();
}

void checkdelays() {
  if (millis() - foutgeluideinde == 250 || millis() - foutgeluideinde - 1 == 250 || millis() - foutgeluideinde + 1 == 250) {
    noTone(passivebuzzer);
  }
  if (millis() - goedgeluideinde == 250 || millis() - goedgeluideinde - 1 == 250 || millis() - goedgeluideinde + 1 == 250) {
    noTone(passivebuzzer);
  }
}

void intro() {
  digitalWrite (lamp1,HIGH);
  delay(200);
  digitalWrite (lamp1,LOW);
  digitalWrite (lamp2,HIGH);
  digitalWrite (lamp4,HIGH);
  delay(200);
  digitalWrite (lamp2,LOW);
  digitalWrite (lamp4,LOW);
  digitalWrite (lamp3,HIGH);
  digitalWrite (lamp7,HIGH);
  setColor(85,85,85);
  delay(200);
  digitalWrite (lamp3,LOW);
  digitalWrite (lamp7,LOW);
  setColor(0,0,0);
  digitalWrite (lamp6,HIGH);
  digitalWrite (lamp8,HIGH);
  delay(200);
  digitalWrite (lamp6,LOW);
  digitalWrite (lamp8,LOW);
  digitalWrite (lamp9,HIGH);
  delay(200);
  digitalWrite (lamp9,LOW);
  digitalWrite (lamp3,HIGH);
  delay(200);
  digitalWrite (lamp3,LOW);
  digitalWrite (lamp2,HIGH);
  digitalWrite (lamp6,HIGH);
  delay(200);
  digitalWrite (lamp2,LOW);
  digitalWrite (lamp6,LOW);
  digitalWrite (lamp1,HIGH);
  digitalWrite (lamp9,HIGH);
  setColor(85,85,85);
  delay(200);
  digitalWrite (lamp1,LOW);
  digitalWrite (lamp9,LOW);
  setColor(0,0,0);
  digitalWrite (lamp4,HIGH);
  digitalWrite (lamp8,HIGH);
  delay(200);
  digitalWrite (lamp4,LOW);
  digitalWrite (lamp8,LOW);
  digitalWrite (lamp7,HIGH);
  delay(200);
  digitalWrite (lamp1,LOW);
  setColor(85,85,85);
  digitalWrite (lamp2,HIGH);
  delay(100);
  digitalWrite (lamp3,HIGH);
  delay(100);
  digitalWrite (lamp6,HIGH);
  delay(100);
  digitalWrite (lamp9,HIGH);
  delay(100);
  digitalWrite (lamp8,HIGH);
  delay(100);
  digitalWrite (lamp7,HIGH);
  delay(100);
  digitalWrite (lamp4,HIGH);
  delay(100);
  digitalWrite (lamp1,HIGH);
  delay(100);
  digitalWrite (lamp2,LOW);
  delay(100);
  digitalWrite (lamp3,LOW);
  delay(100);
  digitalWrite (lamp6,LOW);
  delay(100);
  digitalWrite (lamp9,LOW);
  delay(100);
  digitalWrite (lamp8,LOW);
  delay(100);
  digitalWrite (lamp7,LOW);
  delay(100);
  digitalWrite (lamp4,LOW);
  delay(100);
  digitalWrite (lamp1,LOW);
}

void zetnieuwekleur() {
  dekleur = kleuren[random (4)];
  restmaker(dekleur);
  lampmaker(dekleur);
  brandlampjesmaker();
  //Serial.println(delamp);
  switch (dekleur) {
    case GEEL:
      setColor(160,40,0);
      //Serial.println("Geel");
      break;
    case GROEN:
      setColor(0,255,0);
      //Serial.println("Groen");
      break;
    case ROOD:
      setColor(255,0,0);
      //Serial.println("Rood");
      break;
    case BLAUW:
      setColor(0,0,255);
      //Serial.println("Blauw");
      break;
  }
}

void nakijken () {
  if (IrReceiver.decode()) {
    int c =IrReceiver.decodedIRData.command;
    Serial.print("signaal is :");
    Serial.println(c);
    IrReceiver.resume(); // Receive the next value
    if (c == codes[delamp]){
//    if (c == 90){
      nieuwelampnodig = 1;
      punten++;
      goedgeluid();
      Serial.println("goed");
    }
    else if (c != 0 && millis() - vorigsignaaltijd >= 200){
      punten--;
      foutgeluid();
      Serial.println("fout");
    }
    vorigsignaaltijd = millis();
    Serial.println(millis());
  }
}

void allesuit() {
  digitalWrite(lamp1,LOW);
  digitalWrite(lamp2,LOW);
  digitalWrite(lamp3,LOW);
  digitalWrite(lamp4,LOW);
  setColor(0,0,0);
  digitalWrite(lamp6,LOW);
  digitalWrite(lamp7,LOW);
  digitalWrite(lamp8,LOW);
  digitalWrite(lamp9,LOW);
  noTone(passivebuzzer);
}

void tijdkijker(){
  if (millis() - start == 30000){
    allesuit();
    //Serial.println(punten);
    getallenbrander(punten);
  }
}

void getallenbrander(byte getal){
  Serial.println(punten);
  int getal100tal = getal / 100;
  byte getal100rest = getal%100;
  int getal10tal = getal100rest / 10;
  int getal1tal = getal%10;
  if (getal100tal == 5){
    setColor(85,85,85);
  }
  else if (getal100tal == 0){
    for(int i = 0;i < 9; i++){
      digitalWrite(allelampjes[i],HIGH);
    }
  }
  else{
    digitalWrite(allelampjes[getal100tal],HIGH);
  }
  delay(5000);
  allesuit();
  delay(100);
  if (getal10tal == 5){
    setColor(85,85,85);
  }
  else if (getal10tal == 0){
    for(int i = 0;i < 9; i++){
      digitalWrite(allelampjes[i],HIGH);
    }
  }
  else{
    digitalWrite(allelampjes[getal10tal-1],HIGH);
  }
  delay(5000);
  allesuit();
  delay(100);
  if (getal1tal == 5){
    setColor(85,85,85);
  }
  else if (getal10tal == 0){
    for(int i = 0;i < 9; i++){
      digitalWrite(allelampjes[i],HIGH);
    }
  }
  else{
    digitalWrite(allelampjes[getal1tal],HIGH);
  }
  delay(5000);
  allesuit();
  delay(2000);
  //resetFunc();
}

void setup() {
  // put your setup code here, to run once:
  intro();
  Serial.begin(115200);
  Serial.println("Doe maar iets");
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  pinMode(rgbrood, OUTPUT);
  pinMode(rgbblauw, OUTPUT);
  pinMode(rgbgroen, OUTPUT);
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);
  pinMode(lamp4, OUTPUT);
  pinMode(lamp6, OUTPUT);
  pinMode(lamp7, OUTPUT);
  pinMode(lamp8, OUTPUT);
  pinMode(lamp9, OUTPUT);
  //pinMode(passivebuzzer, OUTPUT);
  codes[lamp1] = 12;
  codes[lamp2] = 24;
  codes[lamp3] = 94;
  codes[lamp4] = 8;
  codes[lamp6] = 90;
  codes[lamp7] = 66;
  codes[lamp8] = 82;
  codes[lamp9] = 74;
  brandendelampjes[0] = lamp1;
  brandendelampjes[1] = lamp1;
  brandendelampjes[2] = lamp1;
  brandendelampjes[3] = lamp1;
  int seed = analogRead(12);
  //Serial.println(seed);
  randomSeed(seed);
  punten = 0;
  start = millis();
}

void loop() {
   if (nieuwelampnodig == 1){
    lampjeswisselaar(0);
    zetnieuwekleur();
    lampjeswisselaar(255);
    nieuwelampnodig = 0;
  }
  nakijken();
  tijdkijker();
  //Serial.println(millis());
  checkdelays();
  //Serial.println(tijdmeting);
}
