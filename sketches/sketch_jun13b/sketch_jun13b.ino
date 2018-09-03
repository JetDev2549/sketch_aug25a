//Libraries
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define Password_Length 8
//You can edit
int signalPin = 12;

char Data[Password_Length];
char Master[Password_Length] = "DA162CB";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPin[4] = {10, 9, 8, 7};
byte colPin[4] = {6, 5, 4, 3};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPin, colPin, 4, 4);

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.backlight();
  lcd.begin();
  pinMode(signalPin, OUTPUT);
  
}
void loop() {
  lcd.setCursor(0,0);
  lcd.print("Enter Password:");

 
  customKey = customKeypad.getKey();
  if (customKey){
  Data[data_count] = customKey;
  lcd.setCursor(data_count,1);
  lcd.print(Data[data_count]);
  data_count++;
  }
    
  
  if(data_count == Password_Length-1){
    lcd.clear();
  
  if(!strcmp(Data, Master)){
    lcd.print("Welcome");
    digitalWrite(signalPin, HIGH);
    delay(5000);
    digitalWrite(signalPin, LOW);
  }
  else{
    lcd.print("Not Correct");
    delay(1000);
  }

  lcd.clear();
  clearData();
  
  }
  
}

void clearData(){
  while(data_count  !=0){
    Data[data_count--] = 0;
  }
  return;
  }
  
  


