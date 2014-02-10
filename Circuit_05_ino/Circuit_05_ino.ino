const int button1Pin = 2;  // pushbutton 1 pin
const int button2Pin = 3;  // pushbutton 2 pin
const int ledPin =  13;    // LED pin
int lastButton1State = HIGH;
int lastButton2State = HIGH;
int count = 0;
const String beg = "The count is: ";//For some reason the output of debug screws up royally if I just have a string in there, but if I make it a constant it works well. No idea why. 


void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  
  Serial.begin(9600);  
  
}


void loop()
{
  int button1State, button2State;  // variables to hold the pushbutton states

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  if (button1State == LOW && button2State == LOW) {
     count = 0;
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
    Serial.println(beg + count); //Prints out the count
  }
  
  //What happens when button 1 is pressed
  //We check the past state so that if you hold the button down, you 
  //don't get a million presses a second. 
  if (button1State != lastButton1State) {
  
    if (button1State == LOW) {
      count++;
      Serial.println(beg + count);
    }
  }
  
  //What happens when button 2 is pressed
  if (button2State != lastButton2State) {
    if (button2State == LOW) {
      if (count%2==1) {
          digitalWrite(13, HIGH);
      } else {
         digitalWrite(13, LOW); 
      }
      
      if (count%4==2 || count%4==3) {
        digitalWrite(12, HIGH);
      } else {
         digitalWrite(12, LOW); 
      }
      
      if (count%8==4 || count%8==5 || count%8==6 || count%8==7) {
        digitalWrite(11, HIGH);
      } else {
         digitalWrite(11, LOW); 
      }
      
      if (count>7) {
        digitalWrite(10, HIGH);
      } else {
         digitalWrite(10, LOW); 
      }
      
      
    }
    
  }
  
  /*
    Since we can't display more than 15 in binary, if we're over 15 we just light up everything
    */
    if (count>15) {
     delay(1000);
     digitalWrite(13,HIGH); 
     digitalWrite(12,HIGH);
     digitalWrite(11,HIGH);
     digitalWrite(10,HIGH);
     delay(1000);
     digitalWrite(13,LOW); 
     digitalWrite(12,LOW);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     delay(1000);
     digitalWrite(13,HIGH); 
     digitalWrite(12,HIGH);
     digitalWrite(11,HIGH);
     digitalWrite(10,HIGH);
     delay(1000);
     digitalWrite(13,LOW); 
     digitalWrite(12,LOW);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     delay(1000);
     digitalWrite(13,HIGH); 
     digitalWrite(12,HIGH);
     digitalWrite(11,HIGH);
     digitalWrite(10,HIGH);
     delay(1000);
     digitalWrite(13,LOW); 
     digitalWrite(12,LOW);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     delay(1000);
     digitalWrite(13,HIGH); 
     digitalWrite(12,HIGH);
     digitalWrite(11,HIGH);
     digitalWrite(10,HIGH);
     delay(1000);
     digitalWrite(13,LOW); 
     digitalWrite(12,LOW);
     digitalWrite(11,LOW);
     digitalWrite(10,LOW);
     count=0;

    } 
  
  lastButton1State = button1State;
  lastButton2State = button2State;
}


