#include <LiquidCrystal.h>

#include <Stepper.h>

#include <Servo.h>

#include <SR04.h>

#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define TRIG_PIN 12
#define ECHO_PIN 13

Servo myservo1;
Servo myservo2;

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution,  45, 47, 49, 51);

int buttonPin = 18;
int buttonState = 0;

const int rs = 23, en = 25, d4 = 27, d5 = 31, d6 = 33, d7 = 35;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;
long b;

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(8, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(8, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(8, 2, NEO_GRB + NEO_KHZ800);

void builtin() //ISR
{
  buttonState = digitalRead(buttonPin);
  {
      strip1.setPixelColor(1, strip1.Color(0, 0, 0));
      strip2.setPixelColor(1, strip2.Color(0, 0, 0));
      strip3.setPixelColor(1, strip3.Color(0, 0, 0));
      strip1.setPixelColor(3, strip1.Color(0, 0, 0));
      strip2.setPixelColor(3, strip2.Color(0, 0, 0));
      strip3.setPixelColor(3, strip3.Color(0, 0, 0));
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      myservo1.detach();
      myservo2.detach();
            lcd.begin(16, 2);
      lcd.print("Try Again?");

      

 while (true) {
    b = sr04.Distance();   //Return distance in cm
    if (b < 15 && b > 7)  {

       delay(1000);
      strip1.setPixelColor(7, strip1.Color(255, 0, 0));
      strip2.setPixelColor(7, strip2.Color(255, 0, 0));
      strip3.setPixelColor(7, strip3.Color(255, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      lcd.begin(16, 2);
      lcd.print("Ready...");
      delay(1000);

      strip1.setPixelColor(5, strip1.Color(255, 255, 0));
      strip2.setPixelColor(5, strip2.Color(255, 255, 0));
      strip3.setPixelColor(5, strip3.Color(255, 255, 0));
      lcd.begin(9, 1);
      lcd.print("Set...");
      strip1.show();
      strip2.show();
      strip3.show();
      delay(1000);

      strip1.setPixelColor(3, strip1.Color(0, 255, 0));
      strip2.setPixelColor(3, strip2.Color(0, 255, 0));
      strip3.setPixelColor(3, strip3.Color(0, 255, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      lcd.begin(16, 2);
      lcd.print("Go!");
      delay(1000);


      lcd.begin(16, 2);
      lcd.print("Twinkle Twinkle");
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip1.setPixelColor(3, strip1.Color(0, 0, 0));
      strip2.setPixelColor(3, strip2.Color(0, 0, 0));
      strip3.setPixelColor(3, strip3.Color(0, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      myservo2.attach(9);//connect pin 9 with the control line(the middle line of Servo)
      myservo2.write(400);
      delay(900);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo2.attach(9);
      myservo2.write(400);
      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo2.detach();

      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("Little Star");


      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);

      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.show();
      delay(1000);

      lcd.begin(16, 2);
      lcd.print("How I Wonder");

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      lcd.setCursor(3, 1);
      lcd.print("What You Are");

      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();

      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();

      myservo2.attach(9);
      myservo2.write(400);
      delay(1000);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Up Above The");

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("World So High");
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Like A Diamond");

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("In The Sky");
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Twinkle Twinkle");

      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();
      myservo2.attach(9);//connect pin 9 with the control line(the middle line of Servo)
      myservo2.write(400);
      delay(900);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo2.attach(9);
      myservo2.write(400);
      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo2.detach();

      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("Little Star");


      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);

      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.show();
      delay(1000);

      lcd.begin(16, 2);
      lcd.print("How I Wonder");

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      lcd.setCursor(3, 1);
      lcd.print("What You Are");

      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();

      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();

      myservo2.attach(9);
      myservo2.write(400);
      delay(1000);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(1000);
      lcd.clear();



      strip1.setPixelColor(1, strip1.Color(251, 254, 198));
      strip2.setPixelColor(1, strip2.Color(251, 254, 198));
      strip3.setPixelColor(1, strip3.Color(251, 254, 198));
      strip1.show();
      strip2.show();
      strip3.show();
      delay(700);
      lcd.begin(16, 2);
      lcd.print("Congratulations!!!)");
      strip1.setPixelColor(3, strip1.Color(254, 253, 147));
      strip2.setPixelColor(3, strip2.Color(254, 253, 147));
      strip3.setPixelColor(3, strip3.Color(254, 253, 147));
      strip1.show();
      strip2.show();
      strip3.show();
      delay(700);
      strip1.setPixelColor(5, strip1.Color(59, 42, 119));
      strip2.setPixelColor(5, strip2.Color(59, 42, 119));
      strip3.setPixelColor(5, strip3.Color(59, 42, 119));
      strip1.show();
      strip2.show();
      strip3.show();
      delay(700);
      strip1.setPixelColor(7, strip1.Color(10, 2, 39));
      strip2.setPixelColor(7, strip2.Color(10, 2, 39));
      strip3.setPixelColor(7, strip3.Color(10, 2, 39));
      strip1.show();
      strip2.show();
      strip3.show();
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      delay(5900);

      lcd.begin(16, 2);
      lcd.print("Begin Again?");

      strip1.setPixelColor(1, strip1.Color(0, 0, 0));
      strip2.setPixelColor(1, strip2.Color(0, 0, 0));
      strip3.setPixelColor(1, strip3.Color(0, 0, 0));
      strip1.setPixelColor(3, strip1.Color(0, 0, 0));
      strip2.setPixelColor(3, strip2.Color(0, 0, 0));
      strip3.setPixelColor(3, strip3.Color(0, 0, 0));
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
    }
 }
    
  }
}



void setup() {
  Serial.begin(9600);    //Initialization of Serial Port

  strip1.begin();
  strip1.setBrightness(85);
  strip1.show();

  strip2.begin();
  strip2.setBrightness(85);
  strip2.show();

  strip3.begin();
  strip3.setBrightness(85);
  strip3.show();

  myStepper.setSpeed(rolePerMinute);


  lcd.begin(16, 2);
  lcd.print("Hey");
  delay(1000);
  lcd.setCursor(3, 1);
  lcd.print("There!");

  pinMode(buttonPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), builtin, CHANGE); //Definition of interrupt
}

//void LCDtwink() {
//  lcd.begin(16, 2);
//  lcd.print("Twinkle Twinkle");
//  delay(2000);
//  lcd.setCursor(3, 1);
//  lcd.print("Little Star");
//  delay(1800);
//  lcd.clear();
//  delay(200);
//
//  lcd.begin(16, 2);
//  lcd.print("How I Wonder");
//  delay(2000);
//  lcd.setCursor(3, 1);
//  lcd.print("What You Are");
//  delay(1800);
//  lcd.clear();
//  delay(200);
//
//  lcd.begin(16, 2);
//  lcd.print("Up Above The");
//  delay(2000);
//  lcd.setCursor(3, 1);
//  lcd.print("World So High");
//  delay(1800);
//  lcd.clear();
//  delay(200);
//
//
//  lcd.begin(16, 2);
//  lcd.print("Like A Diamond");
//  lcd.setCursor(3, 1);
//  lcd.print("In The Sky");
//  delay(1800);
//  lcd.clear();
//  delay(200);
//
//}
//
//void LCDtwink2 () {
//  lcd.begin(16, 2);
//  lcd.print("Twinkle Twinkle");
//  delay(2000);
//  lcd.setCursor(3, 1);
//  lcd.print("Little Star");
//  delay(1800);
//  lcd.clear();
//  delay(200);
//
//  lcd.begin(16, 2);
//  lcd.print("How I Wonder");
//  lcd.setCursor(3, 1);
//  lcd.print("What You Are :)");
//  delay(1800);
//  lcd.clear();
//  delay(200);
//}

void loop() {
  while (true) {
    a = sr04.Distance();   //Return distance in cm
    if (a < 15 && a > 7)  {
      delay(1000);
      strip1.setPixelColor(7, strip1.Color(255, 0, 0));
      strip2.setPixelColor(7, strip2.Color(255, 0, 0));
      strip3.setPixelColor(7, strip3.Color(255, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      lcd.begin(16, 2);
      lcd.print("Ready...");
      delay(1000);

      strip1.setPixelColor(5, strip1.Color(255, 255, 0));
      strip2.setPixelColor(5, strip2.Color(255, 255, 0));
      strip3.setPixelColor(5, strip3.Color(255, 255, 0));
      lcd.begin(9, 1);
      lcd.print("Set...");
      strip1.show();
      strip2.show();
      strip3.show();
      delay(1000);

      strip1.setPixelColor(3, strip1.Color(0, 255, 0));
      strip2.setPixelColor(3, strip2.Color(0, 255, 0));
      strip3.setPixelColor(3, strip3.Color(0, 255, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      lcd.begin(16, 2);
      lcd.print("Go!");
      delay(1000);


      lcd.begin(16, 2);
      lcd.print("Twinkle Twinkle");
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip1.setPixelColor(3, strip1.Color(0, 0, 0));
      strip2.setPixelColor(3, strip2.Color(0, 0, 0));
      strip3.setPixelColor(3, strip3.Color(0, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
      myservo2.attach(9);//connect pin 9 with the control line(the middle line of Servo)
      myservo2.write(400);
      delay(900);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo2.attach(9);
      myservo2.write(400);
      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo2.detach();

      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("Little Star");


      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);

      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.show();
      delay(1000);

      lcd.begin(16, 2);
      lcd.print("How I Wonder");

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      lcd.setCursor(3, 1);
      lcd.print("What You Are");

      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();

      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();

      myservo2.attach(9);
      myservo2.write(400);
      delay(1000);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Up Above The");

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("World So High");
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Like A Diamond");

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("In The Sky");
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);


      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();


      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(1000);
      lcd.begin(16, 2);
      lcd.print("Twinkle Twinkle");

      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();
      myservo2.attach(9);//connect pin 9 with the control line(the middle line of Servo)
      myservo2.write(400);
      delay(900);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo2.attach(9);
      myservo2.write(400);
      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo2.detach();

      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo1.detach();
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      lcd.setCursor(3, 1);
      lcd.print("Little Star");


      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip2.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo1.attach(9);
      myservo1.write(400);
      strip3.setPixelColor(7, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);

      myservo1.detach();
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip3.show();

      myservo1.attach(9);
      myservo1.write(400);
      strip2.setPixelColor(7, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo1.detach();
      strip2.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.show();
      delay(1000);

      lcd.begin(16, 2);
      lcd.print("How I Wonder");

      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(900);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      delay(100);
      myservo1.attach(9);
      myservo1.write(400);
      strip1.setPixelColor(7, strip1.Color(0, 255, 0));
      strip1.show();
      delay(1000);
      myservo1.detach();
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip1.show();
      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(900);
      myservo2.detach();
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip3.setPixelColor(5, strip3.Color(0, 255, 0));
      strip3.show();
      delay(1000);
      myservo2.detach();
      lcd.setCursor(3, 1);
      lcd.print("What You Are");

      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip3.show();

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(900);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();
      delay(100);

      myservo2.attach(9);
      myservo2.write(400);
      strip2.setPixelColor(5, strip2.Color(0, 255, 0));
      strip2.show();
      delay(1000);
      myservo2.detach();
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip2.show();

      strip1.setPixelColor(5, strip1.Color(0, 255, 0));
      strip1.show();

      myservo2.attach(9);
      myservo2.write(400);
      delay(1000);
      myservo2.detach();
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip1.show();
      delay(1000);
      lcd.clear();



      strip1.setPixelColor(1, strip1.Color(251, 254, 198));
      strip2.setPixelColor(1, strip2.Color(251, 254, 198));
      strip3.setPixelColor(1, strip3.Color(251, 254, 198));
      strip1.show();
      strip2.show();
      strip3.show();
      delay(700);
      lcd.begin(16, 2);
      lcd.print("Congratulations!!!)");
      strip1.setPixelColor(3, strip1.Color(254, 253, 147));
      strip2.setPixelColor(3, strip2.Color(254, 253, 147));
      strip3.setPixelColor(3, strip3.Color(254, 253, 147));
      strip1.show();
      strip2.show();
      strip3.show();
      delay(700);
      strip1.setPixelColor(5, strip1.Color(59, 42, 119));
      strip2.setPixelColor(5, strip2.Color(59, 42, 119));
      strip3.setPixelColor(5, strip3.Color(59, 42, 119));
      strip1.show();
      strip2.show();
      strip3.show();
      delay(700);
      strip1.setPixelColor(7, strip1.Color(10, 2, 39));
      strip2.setPixelColor(7, strip2.Color(10, 2, 39));
      strip3.setPixelColor(7, strip3.Color(10, 2, 39));
      strip1.show();
      strip2.show();
      strip3.show();
      myStepper.step(stepsPerRevolution);
      myStepper.step(stepsPerRevolution);
      delay(5900);

      lcd.begin(16, 2);
      lcd.print("Begin Again?");

      strip1.setPixelColor(1, strip1.Color(0, 0, 0));
      strip2.setPixelColor(1, strip2.Color(0, 0, 0));
      strip3.setPixelColor(1, strip3.Color(0, 0, 0));
      strip1.setPixelColor(3, strip1.Color(0, 0, 0));
      strip2.setPixelColor(3, strip2.Color(0, 0, 0));
      strip3.setPixelColor(3, strip3.Color(0, 0, 0));
      strip1.setPixelColor(5, strip1.Color(0, 0, 0));
      strip2.setPixelColor(5, strip2.Color(0, 0, 0));
      strip3.setPixelColor(5, strip3.Color(0, 0, 0));
      strip1.setPixelColor(7, strip1.Color(0, 0, 0));
      strip2.setPixelColor(7, strip2.Color(0, 0, 0));
      strip3.setPixelColor(7, strip3.Color(0, 0, 0));
      strip1.show();
      strip2.show();
      strip3.show();
    }
  }
}
