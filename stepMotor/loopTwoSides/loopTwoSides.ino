//Declare pin functions on Arduino
#define stp_p 2
#define stp_m 3
#define dir_p 4
#define dir_m 5

int Distance = 0;

void setup() {                 
  pinMode(stp_p, OUTPUT); 
  pinMode(stp_m, OUTPUT);
  pinMode(dir_p, OUTPUT); 
  pinMode(dir_m, OUTPUT); 
  
  digitalWrite(stp_p, LOW);
  digitalWrite(stp_m, LOW);
  digitalWrite(dir_p, LOW);
  digitalWrite(dir_m, LOW);
}

void loop() {

  digitalWrite(stp_p, HIGH);
  delayMicroseconds(1000);          
  digitalWrite(stp_p, LOW);
  delayMicroseconds(1000);
  Distance = Distance + 1;   // record this step
  
  // Check to see if we are at the end of our move
  if (Distance == 12000)
  {
    // Reverse direction (invert DIR signal)
    if (digitalRead(dir_p) == LOW)
    {
      digitalWrite(dir_p, HIGH);
    }
    else
    {
      digitalWrite(dir_p, LOW);
    }
    // Reset our distance back to zero since we're
    // starting a new move
    Distance = 0;
    // Now pause for half a second
    delay(500);
  }
}
