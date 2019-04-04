#include <Servo.h>

Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (locked == false) {
    handleUnlocked();
  }

  if (locked == true) {
    handleLocked();
  }
}

void handleUnlocked() {
  switchVal = digitalRead(switchPin);
    
    // if switch closed (lock reset)
    if (switchVal == HIGH) {
      resetLock();
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
}
void handleLocked() {
  knockVal = analogRead(piezo);

    // increment knocks per attempt (door trying to be opened)
    if (numberOfKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    // unlock mechanism
    if (numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
    }
}

void resetLock() {
  numberOfKnocks = 0;
  locked = true;
}

boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  } else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    Serial.print("Range: ");
    Serial.print(quietKnock);
    Serial.print(" - ");
    Serial.println(loudKnock);
    return false;
  }
}
