// Project 2 "Music Box"
// By: Lauren Marone


 #include <analogWrite.h>
 
// Output Numbers
const int RedLED = 12;  
const int GreenLED = 27;  
const int BlueLED = 33; 
const int YellowLED = 32; 

//Input Numbers
const int buttonP = A0;  
const int POT = A1;  
const int buttonPTwo = A2;

//Other Variables
int POTval= 0;

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonStateTwo = 0;         


//Array
char *kissStrings[] = {"Heaven's on Fire", "Rock And Roll All Nite", "Beth", 
                        "Love Gun", "I Was Made For Lovin' You", "Shout It Out Loud"};
 
void setup(){
  Serial.begin(9600);

  randomSeed(analogRead(0));
  
  pinMode(POT, INPUT);
  pinMode(buttonP, INPUT);
  pinMode(buttonPTwo, INPUT);
  
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
}
 
void loop(){
  
//POT-----------------------------------------------
//When potentiometer is turned one way, the "music volume" will lower (the light will dim) 
//and when turned the opposite way, the "volume" will increase (light will get brighter).
    
    POTval = analogRead(POT);   
    Serial.print("\t POTval: ");
    Serial.println(POTval);
    delay(50);
  
    analogWrite(YellowLED, POTval / 16);
    

// BUTTON-------------------------------------------
//When the white button is pressed, the "music" will start "playing" (the RGB LED  light will turn 
//green) and when it is pressed again the "music" will stop "playing" (the light turns red).

    buttonState = digitalRead(buttonP);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
    } 
    delay(50);
  }
  
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(RedLED, HIGH);
    digitalWrite(GreenLED, LOW);
    digitalWrite(BlueLED, LOW);
  } 
  else {
    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
    digitalWrite(BlueLED, LOW);
  }

//String----------------------------------------------
//When the yellow button is pressed, the music box will "shuffle" the songs and "play" a random
//one (Arduino will print a random KISS song title from an array).

  buttonStateTwo = digitalRead(buttonPTwo);
  if (buttonStateTwo == HIGH){
    Serial.println(kissStrings[random(0,5)]);
    delay(500);
  }

 
  
}
