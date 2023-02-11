void hoatdong1()
{
  
  if (toltal_count < turn) {
    if(digitalRead(right_limit)==0)
    {
      digitalWrite(dir2,HIGH);
    }
    if(digitalRead(left_limit)==0)
    {
      digitalWrite(dir2,LOW);
    }
   
    for (int i =0; i<turn ;i++)
    {
      screw_steps += 0.1;
      if(screw_steps = wire_size_array[wire_size_col])
      {
//digitalWrite(dir1,HIGH);
        digitalWrite(step2,HIGH);
        digitalWrite(step1,HIGH);
        delayMicroseconds(5);
        digitalWrite(step1,LOW);
        digitalWrite(step2,LOW);
        delayMicroseconds(5);
        toltal_count+=1;
        lcd.setCursor(0,3);
        lcd.print(toltal_count);
      }
      else
      {
        //digitalWrite(dir1,HIGH);
        digitalWrite(step1,HIGH);
        delayMicroseconds(5);
        digitalWrite(step1,LOW);
        delayMicroseconds(5);
        toltal_count +=1;
         lcd.setCursor(0,3);
        lcd.print(toltal_count);
        
      }
     
      Serial.println(toltal_count);
    }
  }
  else 
  {
     lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(turn);
    lcd.setCursor(5, 0);
    lcd.print("vong");
    lcd.setCursor(0, 2);
    lcd.print("----Hoang thanh---");
  }
}
