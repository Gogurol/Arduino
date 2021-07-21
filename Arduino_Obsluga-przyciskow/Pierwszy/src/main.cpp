#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int8_t ktory_przycisk;//zmienna gdzie przechowywane jest oznaczenie przycisku

void setup() {

  lcd.begin(16,2); //lcd column and rows
  lcd.setCursor(0,0);
  lcd.print("Stan przycisku");
  pinMode(0,OUTPUT);
}

void sprawdz_przycisk(int przycisk){

  if (przycisk < 60)//right
  {
    ktory_przycisk = 4;
  }
  else if (przycisk < 200)//up
  {
    ktory_przycisk = 2;
  }
  
  else if (przycisk < 400)//DOWN
  {
    ktory_przycisk = 3;
  }
  else if (przycisk < 600)//LEFT
  {
    ktory_przycisk = 1;
  }
  else if (przycisk < 800)//select
  {
    ktory_przycisk = 5;
  }
  else ktory_przycisk = 0;
}

void wyswietl(int przycisk){

  lcd.setCursor(0,1);

  if (przycisk != 0)
  {
    switch (przycisk)
    {
    case 1:
      lcd.print("LEFT  ");
      break;
    
    case 2:
      lcd.print("UP    ");
      break;

      case 3:
      lcd.print("DOWN  ");
      break;

      case 4:
      lcd.print("RIGHT ");
      break;

      case 5:
      lcd.print("SELECT");
      break;

    default:
      break;
    }
    
  }
  ktory_przycisk = 0;
}

void loop() {
  
  sprawdz_przycisk(analogRead(0));

  wyswietl(ktory_przycisk);
  
  }