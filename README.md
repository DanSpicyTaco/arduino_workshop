# Introduction to Arduino Workshop

This workshop will introduce you to the basics of the popular microcontroller, Arduino.
Originally, the workshop was designed to take around 60 minutes for up to 30 students.
The presentation slides were made with Canva, and they can be found [here](https://www.canva.com/design/DADbSqPhDms/FKnQA25yyKrIl5hdzbNsbw/view?utm_content=DADbSqPhDms&utm_campaign=designshare&utm_medium=link&utm_source=homepage_design_menu).
If the link above is stale, a back-up PDF is [here](presentation.pdf)

## Workshop Overview

### Background

- An Arduino is a microcontroller and can be considered a bridge between electronic circuits and a computer program.
- Manufacturers make sensors and attachments for the Arduino.
- They are versatile and can be used in robots, sensors, etc.

### Things To Do Before the Workshop

- Pack the appropriate number of kits - e.g. if there are 30 people for a workshop, back ~10 kits
- Ask students to download Arduino IDE before coming to the workshop
- Find 3-4 volunteers to be on per workshop - 1 for presentation, 3 for assisting students; make sure everyone is on the same page by reading the Workshop Outline (this document)

### Timeline of Events

- Presentation: 10-15mins
- Follow Along Demonstration: 20-30mins
- Class evaluation and reflection: 10mins

## Materials Required

| Item Number |        Description         |  Cost (per unit)  |                                                                                                            Comments                                                                                                            |
| :---------: | :------------------------: | :---------------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
|     01      | SparkFun Heart Rate Sensor | \$14.10 (for >21) | Buy from [auselectronicsdirect](https://www.auselectronicsdirect.com.au/heart-rate-pulse-sensor-module-for-arduino-project?gclid=Cj0KCQjwkoDmBRCcARIsAG3xzl_HIQJN281A87j8gLrcDrMn5_wPwXqM0izfEzpKqX6ZugODAUcdTIoaAiCHEALw_wcB) |
|     02      |        Arduino Uno         |       \$19        |                                                                                                        From CREATE UNSW                                                                                                        |
|     03      |      Small Breadboard      |        \$6        |                                                                                                        From CREATE UNSW                                                                                                        |
|     04      |         LEDs (x5)          |        \$1        |                                                                                                        From CREATE UNSW                                                                                                        |

## Presentation and Demonstration Outline

### Coding Basics

- There are many different types of languages
- Data types
  - Conditionals
  - Loops
  - Sensors

### How sensors work

- Heart rate sensor
  - This sensor is very fragile so be careful with it
  - Since this sensor is using light, don't expect to see a classical heartbeat wave, as you can only see that in electrical HR sensors

### Arduino walkthrough

- Go through the main components of the Arduino
- USB Port, DC Power Jack - where the Arduino gets its power
- Power source rails - Arduino can distribute or get its power from here
- Restart button - how the Arduino can restart if something goes wrong
- Digital pins - commonly used for outputting things (e.g. lights/circuits)
- Analog pins - commonly used for inputting things (e.g. sensors)
- Microcontrollers - brains of the Arduino (where all the processing takes place)

### Heart rate sensor set up

- Which wires are used for the sensor, how to set up the breadboard
- +ve wire goes to 5V; -ve wire goes to GND - powers the sensor
- Signal wire sends information to Arduino - goes into an analog pin

### Arduino IDE

- How to create a new file
- Verify, upload and saving
- Make sure Arduino is selected by going to Tools - Port
- `Setup()` - where you can set up all the inputs/outputs (e.g. tell the Arduino which sensor is on which pin)
- `Loop()` - where you actually run through the code you want (e.g. to get the pulse from the sensor)
- Getting readings from the HR sensor
- Go through printing the initial values from the sensor
- Get the groups to test on their own
- Use [01.ino](student_files/01/01.ino)
  Answer is at [no_processing](solutions/no_processing/no_processing.ino)
- Why are the initial readings so bad?
- The sensor actually measures how much infrared light the sensor is receiving
- When you place your finger on it, your heartbeat dilates the blood vessels in your finger and blocks the light - this creates a pulse
- Therefore, we need to do some processing to actually get a heart rate!

### Smoothing out and removing noise from the signal

- Can remove the noise from the signal by taking an average of a bunch of readings (i.e. taking a reading every 20ms)
- Can smooth out the signal by taking an average of the last 20 readings
- You use the removed-noise measurements to smoothen out the signal
- Use [02.ino](student_files/02/02.ino).
  Answer is at [smooth_no_noise](solutions/smooth_no_noise/smooth_no_noise.ino)
- Let students attempt this on their own before showing answer

### Finding the heart rate

- Currently, the values on the y-axis don't mean much
- We're concerned with the time difference between the rising edges of the beats
- You can find a heartbeat by finding a number of increasing consecutive values (i.e. when the curve rises)
- If you calculate the weighted average of the the times between three heartbeats, you get a good approximation of the BPM
- Use [03.ino](student_files/03/03.ino).
  Answer is at [smooth_no_noise](solutions/heart_rate/heart_rate.ino)

### Why it still sucks

- Balance between cost and accuracy
- Low cost PPM HR sensors are pretty inaccurate, so don't use it as a diagnostics machine
- Calibration is hard
