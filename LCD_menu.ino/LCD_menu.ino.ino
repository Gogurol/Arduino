#include <LiquidCrystal.h> //biblioteka do obsługi LCD

LiquidCrystal lcd (8,9,4,5,6,7); //piny pod ktory jest podpiety wyswietlacz
   int numRows = 2;
   int numCols = 16;
   //^ "opis" wyswietlacza: wiersze; kolumny;
   
   char* buttons[] ={"Gora", "W dol", "W lewo", "W prawo", "Wybierz"};
   //^tablica/wskaznik do przechowywania napisow wyswielanych po nacisniecu przyciskow

  unsigned long tap_time = 0UL;   //zmienna na czas wduszenia klawisza (w mils)
  unsigned long wait_time = 100UL ; //zmienna na odczekanie do stabilizacji przycisku
  // ^ bieda debouncing
  int buttons_pin = A0; // tutaj, bo mi funkcje nie widza :(

//Deklaracja znakow i napisowa do menu
byte kursor[] ={
  B00001,
  B00010,
  B00101,
  B01010,
  B10100,
  B01010,
  B00101,
  B00010 };

void setup() {
   
   lcd.begin(numRows,numCols);
   lcd.clear();
   
   pinMode(buttons_pin, INPUT); //pod A0 jest piec przyciskow na shield'zie

   lcd.print("Suwanie kursorem"); 
   lcd.createChar(0,kursor);
     
   lcd.setCursor(0,1);
   lcd.write(byte(0));
   }



void loop() {

  if (analogRead(buttons_pin) <1021) button_decode();
  
}

 byte przyciski (int Volt){

  tap_time = millis();

  if ((Volt ==0 && Volt <140) && (millis() + tap_time > wait_time)) {//przycsk prawo

   return 3;
   
   }
   
  else if ((Volt >144 && Volt <323) && (millis() + tap_time > wait_time)){//przycsk gora
    
   return 0;
  }
  else if ((Volt > 327 && Volt <500) && (millis() + tap_time > wait_time)){//przycsk dol
    
   return 1;
  }
 else if ((Volt > 504 && Volt <740) && (millis() + tap_time > wait_time)){//przycsk lewo
    return 2;
  }
  else if ((Volt > 741 && Volt <1000) && (millis() + tap_time > wait_time)){//przycsk select
    return 4;
  }
  
 }

 void button_decode(){

  int Volt (analogRead(buttons_pin));

  byte button_state = 5;
  button_state = przyciski(Volt);

    switch (przyciski(Volt)) {
    case 3:

      lcd.createChar(0,kursor);
      lcd.setCursor(0,1);
      
      lcd.print(" ");
      lcd.print(byte(0));
      //lcd.print(byte
       
    break;
      
    case  0:
      lcd.clear();
      lcd.print(buttons[0]);
      break;

    case 1:
      
      lcd.clear();
      lcd.print(buttons[1]);
      break;
      
    case 2:
      
    /*  lcd.setCursor(1,1)
      lcd.print(" ");      
      lcd*/
      break;
      
    case 4:
      
      lcd.clear();
      lcd.print(buttons[4]);      
      break;
    
    default:
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  
 }
