// Reaction Timer
// Louis Sullivan 119363083

// include the library code:
#include <LiquidCrystal.h>

// random number
long randomnumber;
// pins for output/input
#define buttonpin 9
#define buzzerpin 13
// state of button
int buttonstate = 0;
// set timer
int reactiontime  = 0;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // get new random number generation
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  pinMode(buzzerpin, OUTPUT);
  pinMode(buttonpin, INPUT);
  // random number between 1 and 9
  randomnumber = random(1, 9);
}

void loop() {
  // set where timer is printed
  lcd.setCursor(0, 0);
  // get the time elapsed in seconds
  lcd.print(millis() / 1000);
  // where to print the random number
  lcd.setCursor(6, 0);
  // print random number
  lcd.print(randomnumber);
  // if the time elapsed equals the random number selected
  if ((millis() / 1000) == randomnumber){
    // turn on the buzzer
    tone(buzzerpin, 1000);
  }
  // read in the buttons current state
  buttonstate = digitalRead(buttonpin);
  // if the button is pressed
  if (buttonstate == HIGH){
    // where to print reaction time
    lcd.setCursor(0, 1);
    // set reaction time equal to time elapsed minus random number
    reactiontime = (millis() / 1000) - randomnumber;
    // print the reactiontime
    lcd.print(reactiontime);
    // turn off buzzer
    noTone(buzzerpin);
    delay(10000);
  }
}
