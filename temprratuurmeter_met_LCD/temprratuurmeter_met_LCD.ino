#include <DHT.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 9, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  lcd.begin(16, 2);
}

void loop()
{
  delay(2000);
  float vochtinlucht = dht.readHumidity();
  float temp°c = dht.readTemperature();
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  lcd.setCursor(0,0); 
  lcd.print("Temp.in°c: ");
  lcd.print(temp°c);
  lcd.setCursor(0,1);
  lcd.print("humidity: ");
  lcd.print(vochtinlucht)
  lcd.print(%)
}

