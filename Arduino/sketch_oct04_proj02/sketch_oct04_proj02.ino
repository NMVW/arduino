int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2); // read switch state at pin2
  if (switchState == LOW) {
    // button is not pressed
    digitalWrite(3, HIGH); // turn green ON
    digitalWrite(4, LOW); // turn red OFF
    digitalWrite(5, LOW); // turn red OFF
    delay(250);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, HIGH);
    delay(500);
  }
  else { // button is pressed
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(100); 
    //toggle lights
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(150);
  }
} // end of loop
