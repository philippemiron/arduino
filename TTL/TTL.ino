// encoder
int pinA = 2;
int pinB = 3;
int pinZ = 4;   

int outPin = 10; // oscilloscope
int val = 0;     // variable to store the read value

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinZ, INPUT);
  
  //pinMode(outPin, OUTPUT);
  pinMode(13, OUTPUT);
}

void davis()
{
  
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}

void loop()
{
  val = digitalRead(pinZ);   // read the input pin
  // print out the state of the button:
  if (val == 1)
  {
    Serial.println("start that piv Davis");
    davis();
  }
  delay(1);        // delay in between reads for stability
}
