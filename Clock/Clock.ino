// BY TERASTACK


#include <LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

//TIME VARIABLES
int hour,minute,seconds,day,mon,year;

void setup(){
  lcd.begin(16,2);
  lcd.print("Clock");
  hour = 00;
  minute = 00;
  seconds = 00;
  day = 1;
  mon = 1;
  year = 22;
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Clock");
  lcd.setCursor(0,1);
  lcd.print(hour);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(seconds);
  lcd.print(" ");
  lcd.print(day);
  lcd.print("/");
  lcd.print(mon);
  delay(1000);
  seconds += 1; // Same as seconds = seconds + 1
  if(seconds == 60){ // we use "==" to CHECK or COMPARE
    seconds = 0; // RESET seconds
    minute += 1; // Add 1 to the minute variable
  }
  if(minute == 60){ 
    minute = 0; // RESET minute
    hour += 1; //Add 1 to the hour var
  }
  if(hour == 24){
    hour = 0; 
    day += 1;
  }
  if(day == 29){
    if(mon == 2){
      if(year/4 != 0){ // This is to check if it is not a leap year  "!=" means NOT EQUAL TO
        day = 1;
        mon += 1;
      }
    }
  }
  if(day == 32){
    if((mon==1) or (mon==3) or (mon==5) or (mon==7) or (mon==8) or (mon==10) or (mon==12)) {
      day = 1;
      mon += 1;
    }
  }
  if(day == 31){
    if((mon==4) or (mon==6) or (mon==9) or (mon==11)) {
      day = 1;
      mon += 1;
    }
  }
  if(day == 30){
    if(mon == 2){
      if(year/4 == 0){ // TO CHECK IF IT IS A LEAP YEAR
        day = 1;
        mon += 1;
      }
    }
  }
  if(mon == 13){
    year += 1;
    mon = 1;
  }
}
