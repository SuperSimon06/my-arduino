const int knopjerood = 2;
const int knopjeblauw = 4;
const int knopjegroen = 6;
const int knopjelager = 7;
const int knopjehoger = 12;
const int RBGrood = 11;
const int RBGblauw = 10;
const int RBGgroen = 9;
int roodsterkte = 128;
int blauwsterkte = 128;
int groensterkte = 128;
const int stap = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode (knopjerood, INPUT);
  pinMode (knopjeblauw, INPUT);
  pinMode (knopjegroen, INPUT);
  pinMode (knopjelager, INPUT);
  pinMode (knopjehoger, INPUT);
  pinMode (RBGrood, OUTPUT);
  pinMode (RBGblauw, OUTPUT);
  pinMode (RBGgroen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int knopjeroodstatus = digitalRead (knopjerood);
  int knopjeblauwstatus = digitalRead (knopjeblauw);
  int knopjegroenstatus = digitalRead (knopjegroen);
  int knopjelagerstatus = digitalRead (knopjelager);
  int knopjehogerstatus = digitalRead (knopjehoger);
  
  if (knopjeroodstatus == HIGH) {
    if (knopjelagerstatus == HIGH) {
      roodsterkte = roodsterkte - stap;
    }
    if (knopjehogerstatus == HIGH) {
      roodsterkte = roodsterkte + stap;
    }
  }
  if (knopjeblauwstatus == HIGH) {
    if (knopjelagerstatus == HIGH) {
      blauwsterkte = blauwsterkte - stap;
    }
    if (knopjehogerstatus == HIGH) {
      blauwsterkte = blauwsterkte + stap;
    }
  }
  if (knopjegroenstatus == HIGH) {
    if (knopjelagerstatus == HIGH) {
      groensterkte = groensterkte - stap;
    }
    if (knopjehogerstatus == HIGH) {
      groensterkte = groensterkte + stap;
    }
  }
  roodsterkte = constrain(roodsterkte, 0, 255);
  groensterkte = constrain(groensterkte, 0, 255);
  blauwsterkte = constrain(blauwsterkte, 0, 255);
  
  analogWrite (RBGrood, roodsterkte);
  analogWrite (RBGblauw, blauwsterkte);
  analogWrite (RBGgroen, groensterkte);
  delay (10);
}
