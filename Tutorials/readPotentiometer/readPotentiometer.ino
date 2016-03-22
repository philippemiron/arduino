/* Analog Read */
int potPin = A0;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  Serial.begin(1200);
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val);
  delay(10);  
}
 
