void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

}

void loop() {
  Serial.println( digitalRead(7) ); // returns what the input pin reads as a number 0 or 1
  delay(50);
   Serial.println( digitalRead(8) ); // returns what the input pin reads as a number 0 or 1
  delay(50);
  
  if(digitalRead(7) == 0){
    // blinks both LEDs SLOW when button is pressed
    digitalWrite(3, LOW);
    delay(300);
    digitalWrite(3, HIGH);
    delay(300);
    digitalWrite(5, HIGH);
    delay(300);
    digitalWrite(5, LOW);
    }else{
      // switch the state of the LEDs
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      }

      if(digitalRead(8) == 0){  
        // when pressed both lights FAST 
    digitalWrite(3, LOW);
    delay(100);
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    }else{
      // switch the state of the LEDs
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      }

  

}
