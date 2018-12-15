//Speden Spelit made by Dan Backlund 2018.

#include "Button.h" //Button library.
#include "LiquidCrystal.h" //Lcd library.
#include <avr/wdt.h> //Arduino reset library.

#define led_button1 10 
#define led_button2 11 //Led pins.
#define led_button3 12 
#define led_button4 13 

Button S1(A3);
Button S2(A2); //Button pins.
Button S3(A1);
Button S4(A0);

LiquidCrystal lcd (8,9,4,5,6,7); //Lcd pins (info in lcd library).

unsigned long previousMillis=0; //Storing info of previous millis here.

int interval = 1000; //Interval of everyhting with millis in my code.
int ledState=LOW; //State changer for leds.
int level_number_new=0; //Point keeper, should be kept above "backline", or game fails.
int level_number_old=-2; //A "backline", if this sum reaches the same value as point keeper, game is over.
int level=1; //The sum of the level you are currently on is stored here.

int sequence[120]={13,13,11,10,10,13,10,12,10,11,11,12,10,12,11,10,13,13,11,
10,12,12,11,13,11,12,11,10,13,12,11,10,13,12,11,10,10,13,10,12,10,11,11,12,10,
12,11,10,13,13,11,10,12,12,10,13,11,12,13,11,13,12,12,11,13,11,13,10,10,12,11,12,
10,12,11,10,13,13,11,10,12,12,11,13,11,12,11,10,13,12,11,10,13,12,11,10,10,13,10,12,
10,11,11,12,10,12,11,10,13,13,11,10,12,12,11,13,11}; //The sequence for all blinking in this code.


void setup() { //Setup to run once.
  
  Serial.begin(9600); //Open connection with serial port.
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); //pinmode for leds.
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT); 
  starting_in(); //The starting function that greets the player before the real game begins.
  }


void starting_in(){ //The code for the starting function.
  
  digitalWrite(led_button1, LOW); 
  digitalWrite(led_button2, LOW); //Shut down all leds before starting the real game.
  digitalWrite(led_button3, LOW);
  digitalWrite(led_button4, LOW);

  lcd.begin(16,2); //Setting the lcd screen to 16x character long (0-15) & 2x characters high (0-1).
  lcd.setCursor(2,0); //Starting on character 2 on long & character 0 Height.
  lcd.print("Welcome to:"); //Prints this text to the lcd screen (max 16x characters).
  lcd.setCursor(1,1);
  lcd.print("Speden Spelit!");
  delay(3000); //A delay of 3 seconds.
    
  lcd.begin(16,2); //Always when .print is used, use also .begin first to erase the old .print.
  lcd.setCursor(4,0);
  lcd.print("Creator:");
  lcd.setCursor(2,1);
  lcd.print("Dan Backlund");
  delay(2000);
    
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("Buckle up");
  lcd.setCursor(3,1);
  lcd.print("Buttercup!");
  delay(2000);
    
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Game starting in");
  lcd.setCursor(7,1);
  lcd.print("3");
  delay(1000);
    
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Game starting in");
  lcd.setCursor(7,1);
  lcd.print("2");
  delay(1000);
    
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Game starting in");
  lcd.setCursor(7,1);
  lcd.print("1");
  delay(1000);
    
  lcd.begin(16,2);
  lcd.setCursor(3,0);
  lcd.print("Good luck!");
  lcd.setCursor(0,1);
  lcd.print("You sexy beast!");
  delay(1000);
  }


void score_text(){ //Lcd score text after failing the game.
  
  ledState=HIGH; //I wanted leds to turn on here.
  
  digitalWrite(led_button1, ledState);
  digitalWrite(led_button2, ledState);
  digitalWrite(led_button3, ledState);
  digitalWrite(led_button4, ledState);
        
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("Your score is:");
  lcd.setCursor(7,1);
  lcd.print(level_number_new);
  delay(2000);
  }


void rank_text(){ //Lcd rank text after failing the game.
  
  ledState=LOW; //I wanted leds to turn off here.
  int x=level; //State changer for the text on lcd, that gives your rank name.
  
  digitalWrite(led_button1, ledState);
  digitalWrite(led_button2, ledState);
  digitalWrite(led_button3, ledState);
  digitalWrite(led_button4, ledState);
  
  if(x==1){ //These go from 1-21, x=level tells you what rank should be used.
        
          lcd.begin(16,2);
          lcd.setCursor(0,0);
          lcd.print("You reached rank");
          lcd.setCursor(4,1);
          lcd.print("Pathetic");
          delay(2000);
          }
          
          if(x==2){
            
            lcd.begin(16,2);
            lcd.setCursor(0,0);
            lcd.print("You reached rank");
            lcd.setCursor(3,1);
            lcd.print("Sad Person");
            delay(2000);
            }
            
            if(x==3){
              
              lcd.begin(16,2);
              lcd.setCursor(0,0);
              lcd.print("You reached rank");
              lcd.setCursor(4,1);
              lcd.print("Failure");
              delay(2000);
              }
              
              if(x==4){
                
                lcd.begin(16,2);
                lcd.setCursor(0,0);
                lcd.print("You reached rank");
                lcd.setCursor(3,1);
                lcd.print("Salad Leaf");
                delay(2000);
                }
                
                if(x==5){
                  
                  lcd.begin(16,2);
                  lcd.setCursor(0,0);
                  lcd.print("You reached rank");
                  lcd.setCursor(5,1);
                  lcd.print("Snail");
                  delay(2000);
                  }
                  
                  if(x==6){
                    
                    lcd.begin(16,2);
                    lcd.setCursor(0,0);
                    lcd.print("You reached rank");
                    lcd.setCursor(5,1);
                    lcd.print("Maggot");
                    delay(2000);
                    }
                    
                    if(x==7){
                      
                      lcd.begin(16,2);
                      lcd.setCursor(0,0);
                      lcd.print("You reached rank");
                      lcd.setCursor(1,1);
                      lcd.print("Walking Beetle");
                      delay(2000);
                      }
                      
                      if(x==8){
                        
                        lcd.begin(16,2);
                        lcd.setCursor(0,0);
                        lcd.print("You reached rank");
                        lcd.setCursor(1,1);
                        lcd.print("Flying Beetle");
                        delay(2000);
                        }
                        
                        if(x==9){
                          
                          lcd.begin(16,2);
                          lcd.setCursor(0,0);
                          lcd.print("You reached rank");
                          lcd.setCursor(1,1);
                          lcd.print("Fast Butterfly");
                          delay(2000);
                          }
                          
                          if(x==10){
                            
                            lcd.begin(16,2);
                            lcd.setCursor(0,0);
                            lcd.print("You reached rank");
                            lcd.setCursor(0,1);
                            lcd.print("Special Olympics");
                            delay(2000);
                            }
                            
                            if(x==11){
                              
                              lcd.begin(16,2);
                              lcd.setCursor(0,0);
                              lcd.print("You reached rank");
                              lcd.setCursor(4,1);
                              lcd.print("Goopher");
                              delay(2000);
                              }
                              
                              if(x==12){
                                
                                lcd.begin(16,2);
                                lcd.setCursor(0,0);
                                lcd.print("You reached rank");
                                lcd.setCursor(5,1);
                                lcd.print("Snake");
                                delay(2000);
                                }
                                
                                if(x==13){
                                  
                                  lcd.begin(16,2);
                                  lcd.setCursor(0,0);
                                  lcd.print("You reached rank");
                                  lcd.setCursor(6,1);
                                  lcd.print("Cat");
                                  delay(2000);
                                  }
                                  
                                  if(x==14){
                                    
                                    lcd.begin(16,2);
                                    lcd.setCursor(0,0);
                                    lcd.print("You reached rank");
                                    lcd.setCursor(6,1);
                                    lcd.print("Dog");
                                    delay(2000);
                                    }
                                    
                                    if(x==15){
                                      
                                      lcd.begin(16,2);
                                      lcd.setCursor(0,0);
                                      lcd.print("You reached rank");
                                      lcd.setCursor(6,1);
                                      lcd.print("Lion");
                                      delay(2000);
                                      }
                                      
                                      if(x==16){
                                        
                                        lcd.begin(16,2);
                                        lcd.setCursor(0,0);
                                        lcd.print("You reached rank");
                                        lcd.setCursor(6,1);
                                        lcd.print("Wolf");
                                        delay(2000);
                                        }
                                        
                                        if(x==17){
                                          
                                          lcd.begin(16,2);
                                          lcd.setCursor(0,0);
                                          lcd.print("You reached rank");
                                          lcd.setCursor(5,1);
                                          lcd.print("Eagle");
                                          delay(2000);
                                          }
                                          
                                          if(x==18){
                                            
                                            lcd.begin(16,2);
                                            lcd.setCursor(0,0);
                                            lcd.print("You reached rank");
                                            lcd.setCursor(2,1);
                                            lcd.print("Santa Claus");
                                            delay(2000);
                                            }
                                            
                                            if(x==19){
                                              
                                              lcd.begin(16,2);
                                              lcd.setCursor(0,0);
                                              lcd.print("You reached rank");
                                              lcd.setCursor(1,1);
                                              lcd.print("Master Wizard");
                                              delay(2000);
                                              }
                                              
                                              if(x==20){
                                                
                                                lcd.begin(16,2);
                                                lcd.setCursor(0,0);
                                                lcd.print("You reached rank");
                                                lcd.setCursor(2,1);
                                                lcd.print("Dan Backlund");
                                                delay(2000);
                                                }
                                                
                                                if(x==21){
                                                  
                                                  lcd.begin(16,2);
                                                  lcd.setCursor(0,0);
                                                  lcd.print("You reached rank");
                                                  lcd.setCursor(2,1);
                                                  lcd.print("A Sexy Fucker ;)");
                                                  delay(2000);
                                                  }
                                                  
                                                  ledState=LOW; //I want to turn leds off here.
                                                  }

                                                  
void level_text(){ //Lcd text for the current level you are on.
  
  unsigned long currentMillis = millis(); //Setup the memory for current Millis.
  
  if (currentMillis - previousMillis >= interval) {
    
    int x=level; //X = level number that prints on the display while playing.
    
    lcd.begin(16,2);
    lcd.setCursor(5,0);
    lcd.print("level:");
    lcd.setCursor(7,1);
    lcd.print(x);
    }
   }

   
void one_pressed(){ //Function for button 1, (all 1-4 buttons have same functions).
  
  if(digitalRead(led_button1)==HIGH){ //When led 1 is on.
    
    if(level_number_new==level_number_old){ //If old number reaches the new and fails the game.
      
      lcd.begin(16,2);
      lcd.setCursor(3,0);
      lcd.print("Too slow!");
      lcd.setCursor(0,1);
      lcd.print("You have failed!");
      delay(2000);
      
      you_fail(); //Function when you fail the game.
      }
      
      if(level_number_new!=level_number_old){ //If new number is other than old number, thus keeping the game alive.
        
        if(S1.pressed()){ //When button 1 is pressed.
          
          level_number_new++; //Adding a sum to new, to keep game alive.
          
          digitalWrite(13, LOW); //Shutting down leds after a successful blink & press.
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          }
        if(S2.pressed()||S3.pressed()||S4.pressed()){ //If other buttons than 1 is pressed while led 1 is on it fails the game.
          
          you_fail();
          }
         }
        }
        
        if(digitalRead(led_button1)==LOW){ //When led 1 is off.
          
          if(S1.pressed()){ //If button 1 is pressed while led 1 is off, it fails the game.
            
            lcd.begin(16,2);
            lcd.setCursor(5,0);
            lcd.print("Wrong!");
            lcd.setCursor(0,1);
            lcd.print("You have failed!");
            delay(2000);
            
            you_fail();
            }
           }
          }

          
void two_pressed(){ //Function for button 2.
  
  if(digitalRead(led_button2)==HIGH){
    
    if(level_number_new==level_number_old){
      
      lcd.begin(16,2);
      lcd.setCursor(3,0);
      lcd.print("Too slow!");
      lcd.setCursor(0,1);
      lcd.print("You have failed!");
      delay(2000);
      
      you_fail();
      }
      
      if(level_number_new!=level_number_old){
        
        if(S2.pressed()){
          
          level_number_new++;
          
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          }
          
          if(S1.pressed()||S3.pressed()||S4.pressed()){
            
            you_fail();
            }
           }
          }
          
          if(digitalRead(led_button2)==LOW){
            
            if(S2.pressed()){
              
              lcd.begin(16,2);
              lcd.setCursor(5,0);
              lcd.print("Wrong!");
              lcd.setCursor(0,1);
              lcd.print("You have failed!");
              delay(2000);
              
              you_fail();
              }
             }
            }


void three_pressed(){ //Function for button (3).
  
  if(digitalRead(led_button3)==HIGH){
    
    if(level_number_new==level_number_old){
      
      lcd.begin(16,2);
      lcd.setCursor(3,0);
      lcd.print("Too slow!");
      lcd.setCursor(0,1);
      lcd.print("You have failed!");
      delay(2000);
      
      you_fail();
      }
      
      if(level_number_new!=level_number_old){
        
        if(S3.pressed()){
          
          level_number_new++;
          
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          }
          
          if(S2.pressed()||S1.pressed()||S4.pressed()){
            
            you_fail();
            }
           }
          }
          
          if(digitalRead(led_button3)==LOW){
            
            if(S3.pressed()){
              
              lcd.begin(16,2);
              lcd.setCursor(5,0);
              lcd.print("Wrong!");
              lcd.setCursor(0,1);
              lcd.print("You have failed!");
              delay(2000);
              you_fail();
              }
             }
            }


void four_pressed(){ //Function for button (4).
  
  if(digitalRead(led_button4)==HIGH){
    
    if(level_number_new==level_number_old){
      
      lcd.begin(16,2);
      lcd.setCursor(3,0);
      lcd.print("Too slow!");
      lcd.setCursor(0,1);
      lcd.print("You have failed!");
      delay(2000);
      
      you_fail();
      }
      
      if(level_number_new!=level_number_old){
        
        if(S4.pressed()){
          
          level_number_new++;
          
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          digitalWrite(10, LOW);
          }
          
          if(S2.pressed()||S3.pressed()||S1.pressed()){
            
            you_fail();
            }
           }
          }
          
          if(digitalRead(led_button4)==LOW){
            
            if(S4.pressed()){
              
              lcd.begin(16,2);
              lcd.setCursor(5,0);
              lcd.print("Wrong!");
              lcd.setCursor(0,1);
              lcd.print("You have failed!");
              delay(2000);
              you_fail();
              }
             }
            }

            
void level_climb(){ //Interval for each level, 21x levels with 5x sequences each level.
  
  if(level_number_new<=5){
    
    interval=1000;
    level=1;
    }
    
    if(level_number_new>5 && level_number_new<=10){
    interval=970;
    level=2;
    }
    
    if(level_number_new>10 && level_number_new<=15){
    interval=940;
    level=3;
    }

    if(level_number_new>15 && level_number_new<=20){
    interval=905;
    level=4;
    }

    if(level_number_new>20 && level_number_new<=25){
    interval=870;
    level=5;
    }

    if(level_number_new>25 && level_number_new<=30){
    interval=835;
    level=6;
    }

    if(level_number_new>30 && level_number_new<=35){
    interval=770;
    level=7;
    }

    if(level_number_new>35 && level_number_new<=40){
    interval=720;
    level=8;
    }

    if(level_number_new>40 && level_number_new<=45){
    interval=665;
    level=9;
    }

    if(level_number_new>45 && level_number_new<=50){
    interval=625;
    level=10;
    }

    if(level_number_new>50 && level_number_new<=55){
    interval=585;
    level=11;
    }

    if(level_number_new>55 && level_number_new<=60){
    interval=535;
    level=12;
    }

    if(level_number_new>60 && level_number_new<=65){
    interval=485;
    level=13;
    }

    if(level_number_new>65 && level_number_new<=70){
    interval=445;
    level=14;
    }

    if(level_number_new>70 && level_number_new<=75){
    interval=425;
    level=15;
    }

    if(level_number_new>75 && level_number_new<=80){
    interval=410;
    level=16;
    }

    if(level_number_new>80 && level_number_new<=85){
    interval=385;
    level=17;
    }

    if(level_number_new>85 && level_number_new<=90){
    interval=355;
    level=18;
    }

    if(level_number_new>90 && level_number_new<=95){
    interval=335;
    level=19;
    }

    if(level_number_new>95 && level_number_new<=100){
    interval=250;
    level=20;
    }
    if(level_number_new>100 && level_number_new<=101){
    interval=50;
    level=21;
   }
  }

  
void timer_for_game(){ //Millis timer for the whole game, instead of using delay.
  
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    
    if (ledState == LOW) {
      
      ledState = HIGH;
      level_number_old++; //Raising the old sum each time led turns on.
      }
      
      else {
        
        ledState = LOW;
        }
        
        digitalWrite(sequence[level_number_new], ledState); //Using the long sequence for leds to turn on or off by ledState.
        }
       }


void you_fail(){ //Function for after failing the game, to be able to see your score, rank & reset arduino.
  
  delay(1000);
  
  int x=0;
  int i=0;
  
  for(i=0; i<=2; i++){ //Looping for 3 times.
    
    score_text();
    rank_text();
    }
    
    while(x<1){ //Loop forever, because x=0.
      
      int y=digitalRead(A0);
      
      digitalWrite(led_button4, HIGH);
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("Hold button (4)");
      lcd.setCursor(0,1);
      lcd.print("start new game!");
      delay(1000);
      
      if(y==0){ //Digitalread pin A0, if it´s pushed/kept while reading, starts this function.
        
        wdt_enable(WDTO_15MS); //Reset arduino after 15ms.
        }
       }
      }


void victory(){ //Function for reaching point 101.
  
  int x=0;
  int y=0;
  
  if(level_number_new==101){ //When new number is 101.
    
    for(x=0; x<=0; x++){ //Loop for 1 time.
      
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("You have beaten-");
      lcd.setCursor(3,1);
      lcd.print("my game!!!");
      delay(2000);
            
      lcd.begin(16,2);
      lcd.setCursor(1,0);
      lcd.print("I´m so happy-");
      lcd.setCursor(4,1);
      lcd.print("for you!");
      delay(2000);
            
      lcd.begin(16,2);
      lcd.setCursor(0,0);
      lcd.print("You will never-");
      lcd.setCursor(0,1);
      lcd.print("again achieve...");
      delay(2000);
            
      lcd.begin(16,2);
      lcd.setCursor(4,0);
      lcd.print("ANYTHING-");
      lcd.setCursor(0,1);
      lcd.print("in your life :D");
      delay(2000);
      }
      
      while(y<1){
        
        int i=digitalRead(A0);
        
        lcd.begin(16,2);
        lcd.setCursor(0,0);
        lcd.print("Hold 'THE' butt");
        lcd.setCursor(1,1);
        lcd.print("You know... ;)");
        delay(1000);
        
        if(i==0){ 
          
          wdt_enable(WDTO_15MS);
          }
         }
        }
       }

                         
void loop(){ //Always looping, have these functions to loop, so that the game runs.

level_text();

level_climb();
timer_for_game();

one_pressed();
two_pressed();
three_pressed();
four_pressed();

victory();
}
    
