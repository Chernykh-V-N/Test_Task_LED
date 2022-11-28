// C++ code
//

//Функции всякие (они потом будут, в конце)
void FromSideToSide(bool, bool);
void TurnOff();

void setup()
{
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  
  
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  
}

void loop()
{
  bool button1IsUp = digitalRead(2);
  bool button2IsUp = digitalRead(4);

  
  if(!button1IsUp)
  {
    FromSideToSide(true, true);
      
      //пошли костыли, т.к., если я правильно понимаю, ардуино не поддерживает многопоточность
      int timer = 10000;
      while(timer > 0 && button2IsUp)
      {
        button2IsUp = digitalRead(4);
        delay(10);
        timer -= 10;
      }
    	
    	if(!button2IsUp)
          {
              FromSideToSide(false, true);
          }
        else
          {
          TurnOff();
          }
    
  }
  
  
   //Теперь все то же со второй кнопкой
  if(!button2IsUp)
  {
     FromSideToSide(true, false); 
    
    int timer = 10000;
    while(timer > 0 && button1IsUp)
    {
      button1IsUp = digitalRead(2);
      delay(10);
      timer -= 10;
    }
    if(!button1IsUp)
        {
        	FromSideToSide(false, false);
        }
    else
        {
      	TurnOff();
        }
  }
}
  


  void FromSideToSide(bool s_turn_on /* зажигаем(true) или гасим */,
                     bool s_from_left /*слева начинаем(true) или справа*/)
  {
    int contacts[5];
    
    //костыли пошли, не стоит обращать внимания. Он почему-то не хочет принимать другие варианты
    
    if(s_from_left)
    {
      contacts[0] = 7;
      contacts[1] = 8;
      contacts[2] = 10;
      contacts[3] = 12;
      contacts[4] = 13;
    }
    else
    {
      contacts[0] = 13;
      contacts[1] = 12;
      contacts[2] = 10;
      contacts[3] = 8;
      contacts[4] = 7;
    }
    
    for(int count = 0; count < 5; count++)
    {
     	if(s_turn_on)
        {
         digitalWrite(contacts[count], HIGH); 
        }
      	else
        {
         digitalWrite(contacts[count], LOW); 
        }
      
      delay(1000);
    }
    
  }
  
  void TurnOff()
  {
    int contacts[5] = {7, 8, 10, 12, 13};
    
    for(int count = 0; count < 5; count++)
    {
     digitalWrite(contacts[count], LOW);
    }
  }
  
