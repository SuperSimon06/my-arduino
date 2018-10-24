
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
}

void loop() 
{

  setColor(64,0,0);
  delay(100);
  setColor(128,0,0);
  delay(100);
  setColor(192,0,0);
  delay(100);
  setColor(255,0,0);
  delay(100);
  setColor(255,64,0);
  delay(100);
  setColor(255,128,0);
  delay(100);
  setColor(255,192,0);
  delay(100);
  setColor(192,192,0);
  delay(100);
  setColor(128,192,0);
  delay(100);
  setColor(64,192,0);  
  delay(100);
  setColor(0,192,0);
  delay(100);
  setColor(0,192,64);
  delay(100);
  setColor(0,192,128);
  delay(100);
  setColor(0,192,192);
  delay(100);
  setColor(0,192,255);
  delay(100);
  setColor(0,128,255);
  delay(100);
  setColor(0,64,255);
  delay(100);
  setColor(0,0,255);
  delay(100);
  setColor(0,0,192);
  delay(100);
  setColor(0,0,128);
  delay(100);
  setColor(0,0,64);
  delay(100);
  setColor(0,0,0);
  delay(1000);
  setColor(255,0,0);
  delay(200);
  setColor(0,0,0);
  delay(100);
  setColor(0,0,255);
  delay(200);
  setColor(0,0,0);
  delay(100);
  setColor(0,255,0);
  delay(200);
  setColor(0,0,0);
  delay(100);
  setColor(255,255,255);
  delay(200);
  setColor(0,0,0);
  delay(100);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
