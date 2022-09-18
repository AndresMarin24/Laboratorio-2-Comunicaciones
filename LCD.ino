#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

String entradaSerial="";
bool entradaCompleta=false;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("==BIENVENIDOS==");
  lcd.setCursor (0,1);
  lcd.print("    A BORDO");
  delay(500);
  Serial.begin(9600);
  
}

void loop() { 
  if(entradaCompleta==true){
    Serial.print(entradaSerial);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Corriente");
    lcd.setCursor(0,1);
    lcd.print(entradaSerial + " mA");
       
    entradaSerial="";
    entradaCompleta=false;
    }

}

void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read();
    if(inChar != '|'){
      entradaSerial += inChar;
      }
     if(inChar == '|'){
      entradaCompleta = true;
      }   
    }
  }
