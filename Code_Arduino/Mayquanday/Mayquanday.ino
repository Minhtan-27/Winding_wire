#include "Define.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(dir1, OUTPUT);
  pinMode(step1, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(step2, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(up_btn, INPUT_PULLUP);
  pinMode(dwn_btn, INPUT_PULLUP);
  pinMode(ent_btn, INPUT_PULLUP);
  pinMode(right_limit, INPUT_PULLUP);
  pinMode(left_limit, INPUT_PULLUP);
  digitalWrite(en1, LOW);
  digitalWrite(en2, LOW);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Thiet ke mach");
  lcd.setCursor(0, 1);
  lcd.print("Nhom 12");
  lcd.setCursor(0, 2);
  lcd.print("De tai 3");
  lcd.setCursor(0, 3);
  lcd.print("May quan day dong");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly
batdau:
  if (digitalRead(ent_btn) == 0)
  {
    while (digitalRead(ent_btn) == 0) ;
    mode++;
    if (mode > 5)
    {
      mode = 1;
    }
    lcd.clear();
  }
  while (mode == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Chon so vong");
    lcd.setCursor(0, 1);
    lcd.print(turn);

    if (digitalRead(ent_btn) == 0)
    {
      while (digitalRead(ent_btn) == 0); mode++;
      if (mode > 5)
      {
        mode = mode_last;
      }
      lcd.clear();
    }
    if (digitalRead(up_btn) == 0)
    {
      while (digitalRead(up_btn) == 0);
      if (hold_duration > 500)
      {
        turn += 50;

      }
      else
      {
        turn ++;
      }
      if (turn > 9999)
      {
        turn = 9999;
      }
      if (move_state_last != move_state)
      {
        hold_start_time = millis();
      }
      hold_duration = millis() - hold_start_time;
      lcd.print("   ");
    }
    else if ( digitalRead(dwn_btn)==0)
    {
      if (hold_duration > 500)
      {
        turn -= 50;
      }
      else
      {
        turn--;
      }
      if (turn < 0);
      {
        turn = 0;
      }
      if (move_state_last != move_state)
      {
        hold_start_time = millis();

      }
      hold_duration = millis() - hold_start_time;
      lcd.print(" ");
    }
    else {
      hold_start_time = 0;
      hold_duration = 0;
    }
  }
  while (mode == 2)
  {
    lcd.setCursor(0, 0);
    lcd.print("Chon loai day:");
    lcd.setCursor(0, 1);
    lcd.print(wire_size_array[wire_size_col]);
    lcd.setCursor(7, 1);
    lcd.print("mm");
    if (digitalRead(ent_btn) == 0)
    {
      while (digitalRead(ent_btn) == 0);
      mode++;
      if (mode > 5)
      {
        mode = mode_last;
      }
      lcd.clear();
    }

    if (digitalRead(up_btn)==0)
    {
      while (digitalRead(up_btn)==0);
      wire_size_col ++;
      if ( wire_size_col > 16)
      {
        wire_size_col = 16;
      }
    }
    else if (digitalRead(dwn_btn)==0)
    {
      while (digitalRead (dwn_btn)==0);
      wire_size_col--;
      if (move_state_last = move_state)
      {
        hold_start_time = millis();
      }
      hold_duration = millis() - hold_start_time;
    }
    if (wire_size_col < 0)
    {
      wire_size_col = 0;
    }


    else
    {
      hold_start_time = 0;
      hold_duration = 0;
    }
  }

  while (mode == 3)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lenght ong day?");
    lcd.setCursor(0, 1);
    lcd.print(Coil_lenght);
    if (digitalRead(ent_btn) == 0)
    {
      while (digitalRead(ent_btn) == 0);
      mode++;
      if (mode > 5)
      {
        mode = mode_last;
      }
      lcd.clear();
    }

    if (digitalRead(up_btn)==0)
    {
      while (digitalRead(up_btn)==0);
      Coil_lenght++;
    }
    else if (digitalRead(dwn_btn)==0)
    {
      while(digitalRead(dwn_btn)==0);
      Coil_lenght --;
      if (move_state_last != move_state)
      {
        hold_start_time = millis();

      }
      hold_duration = millis() - hold_start_time;
    }
    else
    {
      hold_start_time = 0;
      hold_duration = 0;
    }
  }
  while (mode == 4)
  {
    delay(250);
    lcd.setCursor(0, 0);
    lcd.print("Going......");
    delay(250);
    lcd.setCursor(0, 1);
    lcd.print("Tien hanh quan");
    lcd.setCursor(0, 2);
    lcd.print(Coil_lenght);
    lcd.setCursor(5, 2);
    lcd.print("mm day dong");
    lcd.setCursor(0, 3);
    lcd.print("duong kinh: ");
    lcd.setCursor(13, 3);
    lcd.print(wire_size_array[wire_size_col]);
    if (digitalRead(ent_btn) == 0)
    {
      while (digitalRead(ent_btn) == 0);
      mode++;
      if (mode > 5)
      {
        mode = mode_last;
      }
      lcd.clear();
    }

  }
  while (mode == 5)
  {
    //      lcd.clear();
    //      lcd.setCursor(0,0);
    //      lcd.print("Dang quan day");
    //      for(byte i=0;i<20;i++)
    //      {
    //        lcd.setCursor(i,1);
    //        lcd.print(".");
    //        delay(200);
    //      }
    delay(50);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Winding in ...");
    lcd.setCursor(0, 1);
    lcd.print("progress...");

    hoatdong1();
    
    if (digitalRead(ent_btn) == 0)
    {
      while (digitalRead(ent_btn == 0));
      mode = 1 ;
      goto batdau;
    }
  }






}
