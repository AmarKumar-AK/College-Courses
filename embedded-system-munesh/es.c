#include <LiquidCrystal.h>

// initialize the LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// output control pins
#define LCD_CONTRAST_PIN 6
#define LCD_BACKLIGHT_PIN 10

void setup() {
  //set some defaults
  analogWrite(LCD_BACKLIGHT_PIN, 255); //set backlight on
  analogWrite(LCD_CONTRAST_PIN, 50); //set some contrast
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(5000);
}

void loop() {
  lcd.clear();
  lcd.print("Contrast:");
  // loop through values for contrast
  for (int i=0; i <= 150; i++){
    analogWrite(LCD_CONTRAST_PIN, i);
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(80);
  }
  
  analogWrite(LCD_CONTRAST_PIN, 50);

  lcd.clear();
  lcd.print("Back light:");
  // loop through values for backlight
  for (int i=0; i <= 255; i+=2){
    analogWrite(LCD_BACKLIGHT_PIN, i);
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(80);
  }
}

////////////////////////////////////////////////////////////////////////////////

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
 * LCD D6 pin to digital pin 3
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

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// output control pins
#define LCD_CONTRAST_PIN 6
#define LCD_BACKLIGHT_PIN 10
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  lcd.print("Amar kumar");
  lcd.setCursor(0,1);
  lcd.print("CED17I029");
  delay(3000);
  lcd.clear();
  for(int i=0 ; i<5 ; ++i){
    lcd.setCursor(0, 0);
    lcd.print("Blinking Text");
    delay(500);
    lcd.clear();
    delay(500);
  }
  for(int i=0 ; i<=11 ; ++i){
    if(i<=5){
      lcd.setCursor(i, 0);
      lcd.print("Moving Text");
      delay(500);
      lcd.clear();
    }
    else{
      lcd.setCursor(i-6, 1);
      lcd.print("Moving Text");
      delay(500);
      lcd.clear();
    } 
  }
  lcd.setCursor(0, 0);
  lcd.print("Static Text");
  delay(5000);
  lcd.clear();

  lcd.print("Contrast:");
  // loop through values for contrast
  for (int i=0; i <= 150; i++){
    analogWrite(LCD_CONTRAST_PIN, i);
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(80);
  }
  
  analogWrite(LCD_CONTRAST_PIN, 50);

  lcd.clear();
  
  
  

}
 