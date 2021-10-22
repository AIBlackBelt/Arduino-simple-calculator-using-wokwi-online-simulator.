#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(12, 11, A0, A1, A2, A3);
const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '/' },
  { '*', '0', '=', 'R' }
};

uint8_t colPins[COLS] = { 5, 4, 3, 2 }; // Pins connected to C1, C2, C3, C4
uint8_t rowPins[ROWS] = { 9, 8, 7, 6 }; // Pins connected to R1, R2, R3, R4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
boolean firstValue = true;
boolean next = false;
String num1 = "";
String num2 = "";
String op ; 




void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  // you can now interact with the LCD, e.g.:
  lcd.print("start !");
  delay(1000);
  lcd.clear();
  lcd.print("press an operand first !");
  delay(1000);
  lcd.clear();
}

void loop() {
  String key = String(keypad.getKey());

  if (key != NO_KEY) {
    if (key == "R"){
      lcd.clear();
      lcd.print("Reset !");
      delay(1000);
      lcd.clear();
      lcd.print("press an operand first !");
      delay(1000);
      lcd.clear();
      firstValue = true;
      next = false;
      num1 = "";
      num2 = "";
      String op;
    }
  
    else{
    
    if ((key=="0")||(key=="1")||(key=="2")||(key=="3")||(key=="4")||(key=="5")||(key=="6")||(key=="7")||(key=="8")||(key=="9")){
         if (firstValue == true){
           lcd.print(key);
           num1 = num1 + key;
         }
         if (next == true){
           lcd.print(key);
           num2 = num2 + key;
         }
    }
    else{
      if  (key != "="){
         lcd.print(key);
         op = key;
         firstValue = false;
         next = true;
         
      }
      else {
         lcd.print("=");
         if  (op == "+"){
          
         lcd.print(String(num1.toInt()+num2.toInt()));
      }
         if  (op == "-"){
         lcd.print(String(num1.toInt()-num2.toInt()));
      }
      if  (op == "*"){
         lcd.print(String(num1.toInt()*num2.toInt()));
      }
      if  (op == "/"){
         lcd.print(String(num1.toFloat()/num2.toFloat()));
      }
      
    }
    }
    }
  }
  }
