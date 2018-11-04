/* YourDuinoStarter Example: MMA7455 Accelerometer Test
 This example uses the MMA_7455 library by Moritz Kemper  moritz.kemper@zhdk.ch
 Released under Creative Commons Licence
 For use with this module or equivalent: 
 http://yourduino.com/sunshop2/index.php?l=product_detail&p=391
 CONNECTIONS:
 +5V and GND to Arduino/Yourduino (Module has 3.3V regulator)
 SCL - To Arduino / YourDuino A5 (Or Mega SCL pin)
 SDA - To Arduino / YourDuino A4 (Or Mega SDA pin)
 - V1.03 11/18/2013
 Questions?: terry@yourduino.com  
 
/*-----( Import needed libraries )-----*/
#include <Wire.h> //Include the Wire library
#include <MMA_7455.h> //Include the MMA_7455 library

/*-----( Declare Constants and Pin Numbers )-----*/

/*-----( Declare objects )-----*/
MMA_7455 mySensor = MMA_7455(); //Make an instance of MMA_7455

/*-----( Declare Variables )-----*/
char xVal; //Variables for the values from the sensor

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  // Set the sensitivity you want to use
  // 2 = 2g, 4 = 4g, 8 = 8g
  mySensor.initSensitivity(2); // Good for "Tilt" measurements
/* Calibrate the Offset. Calibrate, in Flat position, try to
    get: xVal = 0, yVal = 0, zVal = +63 (1 G)
   !!!Activate this after having the first values read out!!!
   Suggestion: Run this with offsets = 0,0,0 and see needed correction
*/
   mySensor.calibrateOffset(0,0,0); //Uncomment for first try: find offsets
  // mySensor.calibrateOffset(-5.0, 13.0, -12.0); //Then Uncomment and use this

}//--(end setup )---

void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  xVal = mySensor.readAxis('x'); //Read out the 'x' Axis

  delay(250);
/*--( Show tilt [Assumes unit has been calibrated ] )----*/
  if (xVal < -20) Serial.println("LEFT");
  else if (xVal >  20) Serial.println("RIGHT");
  else Serial.println("NOTHING");
}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/


//*********( THE END )***********
