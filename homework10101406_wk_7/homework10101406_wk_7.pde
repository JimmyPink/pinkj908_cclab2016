 

import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

color off = color(4, 79, 111);
color on = color(238, 8, 240);
int i;

int[] values = { Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
 Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW };

void setup() {
  size(470, 200);
 
  println(Arduino.list());
  
   
  arduino = new Arduino(this, Arduino.list()[3], 57600);
  
  // Set the Arduino digital pins as outputs.
  for (int i = 0; i <= 13; i++){
    if (i < 7) arduino.pinMode(i, Arduino.OUTPUT);
   else
  arduino.pinMode(i, Arduino.INPUT);
  }
}

void draw() {
  background(off);
  stroke(on);
  
  for (int i = 0; i <= 7; i++) {
    if (values[i] == Arduino.HIGH)
      fill(on);
    else
      fill(off);
      
    rect(420 - i * 30, 30, 20, 20);
  }
   // Draw a circle whose size corresponds to the value of an analog input.
  noFill();
  for (int i = 0; i <= 5; i++) {
    ellipse(280 + i * 30, 240, arduino.analogRead(i) / 16, arduino.analogRead(i) / 16);
  }
}

void mousePressed()
{
  int pin = (450 - mouseX) / 30;
  
  // Toggle the pin corresponding to the clicked square.
  if (values[pin] == Arduino.LOW) {
    arduino.digitalWrite(pin, Arduino.HIGH);
    values[pin] = Arduino.HIGH;
  } else {
    arduino.digitalWrite(pin, Arduino.LOW);
    values[pin] = Arduino.LOW;
  }
}