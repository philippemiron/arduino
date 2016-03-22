/*
  AnalogReadtoSerial
  Reads an analog input on pin A0, prints the result to the serial monitor.
*/
int analogPin = 0;
int sensorValue = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(analogPin);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(200);        // delay in between reads for stability
}
