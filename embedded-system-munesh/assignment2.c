#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// output control pins
#define LCD_CONTRAST_PIN 6
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  analogWrite(LCD_CONTRAST_PIN, 0);
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

  lcd.print("Dimming Text");
  // loop through values for contrast
  for (int i=0; i <= 150; i++){
    analogWrite(LCD_CONTRAST_PIN, i);
    lcd.setCursor(0, 1);
    //lcd.print(i);
    delay(80);
  }

  lcd.clear();

}