// Global constants
int sensorPin = 0;    // Where our sensor data comes from

void setup() {
  Serial.begin(9600); // Setting up interface with the computer
}

void loop () {
  int currentValue = analogRead(sensorPin);
  Serial.println(currentValue);   // Print the current value to the console
}  
