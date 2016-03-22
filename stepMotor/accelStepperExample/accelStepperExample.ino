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
int dirPin1 = 3;
int stepPin1 = 2;
AccelStepper stepper(1, stepPin1, dirPin1);

// multistepping
//  MS1    MS2    Description
//   L      L     Full step
//   H      L     Half step
//   L      H     1/4 step
//   H      H     1/8 step
int MS1Pin1 = 4;
int MS2Pin1 = 5;

int pos = 1600;
void setup()
{  
  stepper.setMaxSpeed(400);
  stepper.setAcceleration(2000);
  
  // set multi-step resolution
  pinMode(MS1Pin1, OUTPUT);
  pinMode(MS2Pin1, OUTPUT);
  digitalWrite(MS1Pin1, HIGH);
  digitalWrite(MS2Pin1, HIGH);
}
void loop()
{
  stepper.moveTo(pos);
  stepper.run();
}

