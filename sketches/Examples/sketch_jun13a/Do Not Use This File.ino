#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("អ្នក​សុខសប្បាយ​ទេ?");
  lcd.setCursor(0, 1);
  lcd.print("我是粱天xxx");
}

void loop(){
  
}

char pressed = keypad.getKey();
  if (pressed)
  {
    Serial.println(pressed);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(pressed);
  }
}
