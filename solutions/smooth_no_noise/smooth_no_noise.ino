#define samp_size 5
int sensorPin = 0;

// Variables
int reads[samp_size] = {0}; // Number of reads you can take at a time
int ptr = 0;
int sum = 0;
int n;
float reader, last, start, now;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*
   * Remove the noise from the signal here
   */
  n = 0;
  start = millis();
  reader = 0.;
  
  do {
    reader += analogRead (sensorPin); // add the current value
    n++;
    now = millis();
  } while (now < start + 20);         // wait until 20ms have elapsed
  
  reader /= n;                        // take the average of the values in 20ms

  /*
   * Smoothen out the signal here
   */
  sum -= reads[ptr];    // subtract the oldest reading
  sum += reader;        // add the most recent reading
  reads[ptr] = reader;  // replace the oldest reading with the most recent one

  last = float(sum) / samp_size;  // calculate the average of the last 20 points
  
  ptr++;
  ptr %= samp_size;   // Make sure ptr is within samp_size
  
  Serial.println(last); // print the value out
} 
