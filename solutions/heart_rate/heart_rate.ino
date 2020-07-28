#define samp_size 5
#define rise_threshold 5
int sensorPin = 0;

// Variables
int reads[samp_size] = {0}; // Number of reads you can take at a time
int ptr = 0;
int sum = 0;
int n;
float reader, last, start, now, before, first, last_beat, second, third, print_value;
int rise_count;
bool rising;

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
  Serial.println(last);
  /*
   * Convert heartbeats to BPM (heart rate)
   */
  if (last > before) {  // consecutive reading is increasing
    rise_count++;
    if (!rising && rise_count > rise_threshold) { // heartbeat detected
      rising = true;    // Make rising true to prevent the same heartbeat being detected twice
      
      first = millis() - last_beat; // The interval between heartbeats
      last_beat = millis();

      // BPM will be the weighted average of the last three heartbeats
      print_value = 60000. / (0.4 * first + 0.3 * second + 0.3 * third);

      third = second;               // Update the previous heartbeat intervals
      second = first;  
      Serial.print("We are finished :) ");
      Serial.print("Current heart rate: ");
      Serial.println(print_value);
     
    }
  } else { // Curve is falling, reset everything
    rising = false;
    rise_count = 0;
  }
     
  before = last;      // Update the 'before' reading
  ptr++;
  ptr %= samp_size;   // Make sure ptr is within samp_size
} 
