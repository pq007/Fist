float wendu = A0;
  int a = 1;
  int b = 1;
void setup()
{
 Serial.begin(9600);
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
     pinMode(6,OUTPUT);
     pinMode(7,OUTPUT);
     pinMode(4,OUTPUT);
     pinMode(5,OUTPUT);
     pinMode(A0,INPUT);
     digitalWrite(9,HIGH);digitalWrite(8,LOW);
 }
 
void loop()
{ 
  float wendu_=analogRead(wendu);
  while(Serial.available())
   {
     {
        char c=Serial.read();
        if(c == 'z')
        {
          a=a+1;
         Serial.println(c);
         digitalWrite(4,LOW);digitalWrite(5,HIGH);
         digitalWrite(6,HIGH);digitalWrite(7,LOW);delay(15000);
         digitalWrite(6,LOW);digitalWrite(7,LOW);        
        }
       if(c == 's')
       {
         a=0;
         Serial.println(c);
         digitalWrite(6,LOW);digitalWrite(7,LOW);
         digitalWrite(4,LOW);digitalWrite(5,LOW);
       }
       if(c=='f')
       {
         b=b+1;
         Serial.println(c);
         digitalWrite(4,LOW);digitalWrite(5,LOW);
         digitalWrite(6,HIGH);digitalWrite(7,HIGH);delay(15500);
         digitalWrite(6,LOW);digitalWrite(7,LOW);
       }
   }
   }
   
   if(a)
    {
      Serial.println(wendu_);delay(500);
      if(wendu_ > 560)
      {
        if(a==1 ){        
          digitalWrite(4,LOW);digitalWrite(5,HIGH);
          digitalWrite(6,HIGH);digitalWrite(7,LOW);delay(15000);a=a-10;
        }
        digitalWrite(4,LOW);digitalWrite(5,HIGH);delay(1000);
        digitalWrite(6,LOW);digitalWrite(7,LOW);delay(1000);
      }
     if(wendu_ < 538)
       {
         if(b==1){         digitalWrite(4,LOW);digitalWrite(5,LOW);
                           digitalWrite(6,HIGH);digitalWrite(7,HIGH);delay(15500);b=b-10;
                       }
         digitalWrite(4,LOW);digitalWrite(5,LOW);delay(1000);
         digitalWrite(6,LOW);digitalWrite(7,LOW);delay(1000);
       }
      if((wendu_ > 538)&&(wendu_<560))
       {
         digitalWrite(4,LOW);digitalWrite(5,LOW);
         digitalWrite(6,LOW);digitalWrite(7,LOW);
       }
    }

 }

