                                                                               // constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin
int ledPins[]={3,4,5,6,7,8,9};; // the number of the LED pin
int buz = 10;


boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;

boolean playing = false;

int play = 1;

boolean LEDstatus = LOW;

int score = 0;
int highScore = 0;

void setup() 
{
  Serial.begin(9600); 

      pinMode(buz, OUTPUT);
  for (int i =0; i <8; i++)
  {
    pinMode(ledPins[i],OUTPUT);
  }
  pinMode(buttonPin, INPUT);

          for(int a = 2; a > -1; a--)
          {
              digitalWrite(ledPins[a],HIGH);
          }

}
 


void loop() 
{
    Serial.println("Click white Button to Start");

  while(playing == false)
{
  if (digitalRead(buttonPin) ==HIGH) 
  {  
     playing = true;  
  }
}
startLights();

    

//int quick =260;


   score = 0;
//START GAME
  while(playing == true)
  {
          for(int i =0; i<7; i++)
          { if(playing == true)
            {
               digitalWrite(ledPins[i],HIGH);
               playing = check(random(90, 150),i);
               digitalWrite(ledPins[i],LOW);
            }
          }
           for(int i =6; i>0; i--)
          { if(playing == true)
            {
               digitalWrite(ledPins[i],HIGH);
               playing =  check(random(90, 150), i);
               digitalWrite(ledPins[i],LOW);
            }
          }
  }
    if(score > highScore)
    {
      highScore = score;
      Serial.println("\nHIGH SCORE");
      Serial.print("Your Score Was ");
      Serial.println(score);
    }else
    {
      Serial.print("Your Score Was ");
      Serial.println(score);
    }
  delay(200);
      
        digitalWrite(buz, LOW);

//display your score with lights
displayScore(score);


   play = 1;
   playing = false;
   score = 0; 
  Serial.println("\n"); 
  delay(700);
}




//start lights

//Starting Lights
void startLights()
{
      if(score ==0)
    {
      turnOffAll();
          for(int a = 2; a > -1; a--)
          {
              digitalWrite(ledPins[a],HIGH);
          }
      
          for(int i = 3; i > 0; i--)
          {
              Serial.print(i);
              delay(333);
              Serial.print(".");
              delay(333);
              Serial.print(".");
              delay(333);
              if(i ==1) Serial.println("START");
              digitalWrite(ledPins[(i-1)],LOW);
          }
    }else
    {
      turnOffAll();
          for(int i = 3; i > 0; i--)
          {
              Serial.print(i);
              delay(333);
              Serial.print(".");
              delay(333);
              Serial.print(".");
              delay(333);
              if(i ==1) Serial.println("START");
          }      
    }

    delay(100);
}




//turnOff all Lights
void turnOffAll()
{
  for(int g = 6; g > -1; g--)
            {
              digitalWrite(ledPins[g],LOW);
            }
}


//method check for click
boolean check(int time, int led)
{int r =0;
//Serial.println(led);
  for(int a = 0; a < time; a++)
  {
      if (digitalRead(buttonPin) ==HIGH) 
      {
          if(led !=3)
          {
//              digitalWrite(buz, HIGH);
             return false; 
          }else
          {
            r++;
            delay(80);
          }
            
       }
      delay(1);
       if (digitalRead(buttonPin) ==HIGH) 
      {
          if(led !=3)
          {
//              digitalWrite(buz, HIGH);
             return false; 
          }else
          {
             r++;
             delay(80);

          }
            
       }
  }
  if(r > 1)
    {
      Serial.print("SCORE: ");
            Serial.println(++score);
    }
  return true;
}



//score with lights
void displayScore(int score)
{
  int times = 0;
    if( score% 7 == 0)
    {   
      times = score /7;
    }else
    {
      times = (score /7 ) + 1;
    }

    for(int c = 0; c < times; c++)
    {
        if( (c+1) == times)
        {
           if( score% 7 != 0)
           {
            for(int k = 0; k < score% 7 ; k++)
            {
               digitalWrite(ledPins[k],HIGH);
               delay(400);
            }
            
           }else
           {
            for(int j = 0; j < 7; j++)
            {
               digitalWrite(ledPins[j],HIGH);
               delay(400);
            }
           }
        }else
        {
            for(int k = 0; k < 7; k++)
            {
               digitalWrite(ledPins[k],HIGH);
               delay(400);
            }
            turnOffAll();
        }
        
    }

}
