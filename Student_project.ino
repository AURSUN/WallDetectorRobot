/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
*/

#include <LiquidCrystal.h>
#include <Ultrasonic.h>
const int motorPin1  = A1;  // Pin 14 of L293
const int motorPin2  = A2;  // Pin 10 of L293
const int motorPin3  = A3; // Pin  7 of L293
const int motorPin4  = A4;  // Pin  2 of L293
String what="Your travel distance :";
    int Enter_your_travel_distance=0;      //  Car distance
    int Enter_your_campare_value=0;       //  campare value
    int actual;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   //   lcd pins 
Ultrasonic wireless(10,9);              //  * trig pin  * echo pin
void start();                          //   robot insilize
int detection();                      //  dectection moment
void forward();
void backward();
void left();
void right();
void setup() 
{
start();
}

void loop() 
{
    
     actual=detection();
     Serial.println("Ultrasonics distance :\t" +actual);
     Serial.print("Distance from Measure by car\t"+Enter_your_travel_distance);
     logic(Enter_your_campare_value,actual);    //campare value which is contact //actual is actual value which is read by thew ultrasonic
     delay(100);
     travel(Enter_your_travel_distance);  // distace which is measure by robot
}
void start()
{

   lcd.begin(16, 2);
    pinMode(motorPin1, OUTPUT);
      pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
   lcd.setCursor(0, 1);
   delay(500);
   lcd.print("Start your robot Now");
   delay(300);  
}

int detection()
{
 int a=wireless.distanceRead();
   delay(1000);
   return a;
}

int logic(int distance,int value)
{
  if(value<=distance)
   {
     forward();
   }  
  if(value>=distance)
   {
     left();
   } 
}
void backward()
{
     analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(10); 
}
    //This code will turn Motor A counter-clockwise for 2 sec.
void forward()
{ 
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(10);
}
   void left()
  {
   //This code will turn Motor B clockwise for 2 sec.
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(10); 
  }
 void right()
 {
    //This code will turn Motor B counter-clockwise for 2 sec.
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(10);    
 }
 void stop()
   {
    //And this code will stop motors
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  
   }
   void travel(int travel)
   {
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(what+travel);
   }
   

