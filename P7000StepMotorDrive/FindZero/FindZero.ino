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

// step motor def with positive pin
AccelStepper stepper(1, stepPin, dirPin);
const int stepsPerRev = 200;

// Steps
int nbSteps;
int SpeedStepS;

void setup()
{
  // speed and distance
  float SpeedRevS = 1.0;
  nbSteps = 100;
  
  // set multi-step resolution
  float ms_factor = 1;

  /////////////////////////////
  //   Automatic settings    //
  // Do no modify from here! //
  /////////////////////////////
  
  // setting speed and acceleration in step per second
  SpeedStepS = int(SpeedRevS * stepsPerRev / ms_factor);
  stepper.setMaxSpeed(SpeedStepS); // step/s
  stepper.setAcceleration(100); // step/s^2
  
  // set negative pin to LOW
  pinMode(stepPinm, OUTPUT);
  digitalWrite(stepPinm, LOW);
  pinMode(dirPinm, OUTPUT);
  digitalWrite(dirPinm, LOW);
  
  // position  
  stepper.move(nbSteps);
}
  
void loop()
{
  stepper.run();
}
