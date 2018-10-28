
/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 9
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 9, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // set up the LCD's number of columns and rows:
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);
  lcd.print("start");
  irrecv.enableIRIn(); // Start the receiver
}

void legelcd (int rij, int plaats){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(rij,plaats);
  
}
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    lcd.setCursor(0, 0);
    if(results.value != 0xffffffff){
      legelcd(0,0);
    }
    switch (results.value) {
         case 0xff30cf://1
           lcd.print("het was 1,toch");
           break;
         case 0xff18e7://2
           lcd.print("doe normaal");
           lcd.setCursor(0,1);
           lcd.print("MAARTEN");
           break;
         case 0xff7a85://3
           lcd.print("23-5-14");
           break;
         case 0xff10ef://4
           lcd.print("JE STINKT");
           break;
         case 0xff38c7://5
           lcd.print("2+3");
           break;
         case 0xff5aa5://6
           lcd.print("je drukte (1+2");
           lcd.setCursor(0,1);
           lcd.print("+3+4+5+6):3-1 in");
           break;
         case 0xff42bd://7
           lcd.print("18x17-1023=");
           break;
         case 0xff4ab5://8
           lcd.print("HELLO, WORLD");
           break;
         case 0xff52ad://9
           lcd.print("EXPLODEERT IN");
           lcd.setCursor(0, 1);
           lcd.print("3");
           lcd.setCursor(0,1);
           delay(1000);
           lcd.print("2");
           lcd.setCursor(0,1);
           delay(1000);
           lcd.print("1");
           delay(1000);
           legelcd(0,0);
           lcd.print("ERROR:");
           lcd.setCursor(0,1);
           lcd.print("springstof is op");
           break;
    }
    irrecv.resume(); // Receive the next value
  }

}
