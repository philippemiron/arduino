#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("demande moi");
  lcd.setCursor(0,1);
  lcd.print("balle de crystal");
  // add seed
  randomSeed(analogRead(0));
}

void loop() {
  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("La balle dit:");
      lcd.setCursor(0,1);
      
      switch (reply) {
        case 0:
          lcd.print("Oui!");
          break;
        case 1:
          lcd.print("Peut-etre.");
          break; 
       case 2:
          lcd.print("Certainement.");
          break; 
       case 3:
          lcd.print("Possiblement.");
          break; 
       case 4:
          lcd.print("Pas sur.");
          break; 
       case 5:
          lcd.print("Dem encore.");
          break; 
       case 6:
          lcd.print("J'en doute.");
          break; 
       case 7:
          lcd.print("Nope.");
          break;     
      } 
    }
  }
  
  prevSwitchState = switchState;
}
