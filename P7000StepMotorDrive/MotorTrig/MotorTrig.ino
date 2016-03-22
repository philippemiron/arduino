#include <AccelStepper.h>
// Constructor
// AccelStepper mystepper(1, pinStep, pinDirection);
// A stepper motor controlled by a dedicated driver board.
// AccelStepper mystepper(2, pinA, pinB);
// A bipolar stepper motor controlled by an H-Bridge circuit.
// AccelStepper mystepper(4, pinA1, pinA2, pinB1, pinB2);
// A unipolar stepper motor, controlled by 4 transistors.

// Functions
// Speed
// mystepper.setMaxSpeed(stepsPerSecond);
// Sets the maximum speed. The default is very slow, so this must be configured. When controlled by setting position, the stepper will accelerate to move at this maximum speed, and decelerate as it reaches the destination.
// Acceleration
// mystepper.setAcceleration(stepsPerSecondSquared);
// Sets the acceleration to be used, in steps per second per second.

// Define a stepper and the pins it will use
const int stepPin  = 2;
const int stepPinm = 3;
const int dirPin   = 4;
const int dirPinm  = 5;
const int stepsPerRev = 200;
AccelStepper stepper(1, stepPin, dirPin);

// Davis trigger pin
const int trigPin = A0;

// Steps
int nbSteps;

void setup()
{
  float SpeedRevS = 0.6;
  float nbRevs = 0.5;
  
  // set multi-step resolution
  //  MS1    MS2    Description
  //   L      L     Full step
  //   H      L     Half step
  //   L      H     1/4 step
  //   H      H     1/8 step
  pinMode(MS1Pin1, OUTPUT);
  pinMode(MS2Pin1, OUTPUT);
  digitalWrite(MS1Pin1, LOW);
  digitalWrite(MS2Pin1, HIGH);
  
  // set negative pin to LOW
  pinMode(stepPinm, OUTPUT);
  digitalWrite(stepPinm, LOW);
  pinMode(dirPinm, OUTPUT);
  digitalWrite(dirPinm, LOW);
  
  /////////////////////////////
  //   Automatic settings    //
  // Do no modify from here! //
  /////////////////////////////
  
  // setting distance in steps
  nbSteps = int(nbRevs * stepsPerRev * multiStepping(MS1Pin1, MS2Pin1));
  
  // setting speed and acceleration in step per second
  int SpeedStepS = int(SpeedRevS * stepsPerRev * multiStepping(MS1Pin1, MS2Pin1));
  stepper.setMaxSpeed(SpeedStepS); // step/s
  stepper.setAcceleration(5000); // step/s^2
  
  // Trigger Davis 300us
  pinMode(trigPin, OUTPUT);
  TTL(trigPin, 300);
}
  
void loop()
{
  stepper.moveTo(nbSteps);
  stepper.run();
  
  // put motor in Enable mode:
  // the driver chip is still enabled, but
  // all of the final motor drive circuits 
  // are disabled and so no current will flow to the motor
  // (suppose to cool down the chip!)
  if (stepper.distanceToGo() == 0)
  {
    digitalWrite(nenPin1, HIGH);
  }
}

void TTL(int pin, int tDelay)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(tDelay);
  digitalWrite(pin, LOW);
}

//  MS1    MS2    Description
//   L      L     Full step
//   H      L     Half step
//   L      H     1/4 step
//   H      H     1/8 step 
int multiStepping(int MS1, int MS2)
{
  if (digitalRead(MS1) == LOW) {
    if (digitalRead(MS2) == LOW)
      return 1;
    else
      return 4;
  } else {
    if (digitalRead(MS2) == LOW)
      return 2;
    else
      return 8;
  }
}
