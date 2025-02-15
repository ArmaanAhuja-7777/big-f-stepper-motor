/*
  Stepper Motor 90-degree Rotation with Intervals
  stepper-90deg.ino
  Uses MA860H or similar Stepper Driver Unit
  Rotates 90 degrees, stops for 3 seconds, and repeats
*/

// Define pins
int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pin

// Variables
int pd = 2000;       // Pulse Delay period (adjust for speed)
boolean setdir = LOW; // Set initial direction
int stepsPerRevolution = 200; // Steps per full revolution (depends on stepper motor & driver)
int stepsPer90Deg = stepsPerRevolution / 4; // Steps for 90-degree rotation
int stopTime = 3000; // Stop time in milliseconds

void setup() {
  pinMode(driverPUL, OUTPUT);
  pinMode(driverDIR, OUTPUT);
  digitalWrite(driverDIR, setdir); // Set initial direction
}

void loop() {
  // Rotate 90 degrees
  for (int i = 0; i < stepsPer90Deg; i++) {
    digitalWrite(driverPUL, HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL, LOW);
    delayMicroseconds(pd);
  }
  
  // Stop for defined time
  delay(stopTime);
}
