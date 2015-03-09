
#include <Servo.h> // Include code for controlling the servo motor
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created
                
int stopPos = 50; // How many degress to turn before stopping
 
int pos = 0;    // variable to store the servo position 

// Make sure numHits and the number of elements in delays are the same
int numHits = 3; // Number of times to hit the drum
int delays[3] = {200,100,100}; // How long to wait after a drum hit (milliseconds, 1000 ms = 1 second)
int hitNum = 0; // The hit number in the sequence
 
void setup() // The code in this function is run once when the Arduino is turned on
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void hitdrum() // This function has the servo hit a drum. The servo moves a small distance at many increments to make the movement fluid and allow you to adjust the speed
{
  int pauseTime = 10; // How long to wait between moves (milliseconds)
                      // A smaller pauseTime is a faster movement
  int incrementAmt = 5; // How far to move the servo at each step
  
  for(pos = 0; pos < stopPos; pos += incrementAmt)  // Hit the drum
  {     
    myservo.write(pos);    // tell servo to go to position in variable 'pos' 
    delay(pauseTime);
  } 
  
  for(pos = stopPos; pos >=1; pos -= incrementAmt)  // return to original position
  {                                 
    myservo.write(pos);    // tell servo to go to position in variable 'pos' 
    delay(pauseTime);
  } 
  
}
 
void loop() // This function runs repeatedly as long as the Arduino is turned on
{ 
   for(hitNum = 0; hitNum < numHits; hitNum += 1)
   {
     hitdrum();
     delay(delays[hitNum]);
   }
} 
