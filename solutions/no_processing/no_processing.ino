// Global constants
int sensorPin = 0;    // Where our sensor data comes from

void setup() {
  Serial.begin(9600);
}

void loop () {
  int currentValue = analogRead(sensorPin);
  
  // Remove noise here


  // Smoothen output here
  
  

  Serial.println(currentValue);   // Print the current value to the console
}

millis() --> time in ms

start = millis();


curr = millis();

curr - start --> time difference
