#include <DHT.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 9, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DHTTYPE    DHT11     // DHT 11
#define DHT11_PIN 13
DHT dht(DHT11_PIN, DHTTYPE);



void setup(){
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  lcd.begin(16, 2);
}

void loop()
{
  delay(2000);
  float vochtinlucht = dht.readHumidity();
  float tempc = dht.readTemperature();
  
  lcd.setCursor(0,0); 
  if (isnan(tempc)) {
      lcd.print("Temp. niet te lezen");
  } else {
      lcd.print("Temp.in'c: ");
      lcd.print(tempc);
  }
  lcd.setCursor(0,1);
  if (isnan(vochtinlucht)) {
      lcd.print("Vocht niet te lezen");
  } else {
      lcd.print("humidity: ");
      lcd.print(vochtinlucht);
      lcd.print("%");
    
  }
}

