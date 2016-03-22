
int dirPin1 = 3;
int stepPin1 = 2;

void setup() {
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
}

void step(boolean dir, int steps) {
  digitalWrite(dirPin1, dir);
  delay(50);
  for(int i=0; i<steps; i++) {
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(100);
  }
}

void loop() {
  step(true, 6400);
  delay(200);
  step(false, 3200);
  delay(200);
}
