const int rLEDPin = 11;
const int gLEDPin = 9;
const int bLEDPin = 10;

const int rSensPin = A0;
const int gSensPin = A1;
const int bSensPin = A2;

int rLEDValue = 0;
int gLEDValue = 0;
int bLEDValue = 0;

int rSensValue = 0;
int gSensValue = 0;
int bSensValue = 0;


void setup() {
  Serial.begin(9600);
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
}

void loop() {
  rSensValue = analogRead(rSensPin);
  delay(5);
  gSensValue = analogRead(gSensPin);
  delay(5);
  bSensValue = analogRead(bSensPin);
  
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(rSensValue);
  Serial.print("\t Green: ");
  Serial.print(gSensValue);
  Serial.print("\t Blue: ");
  Serial.print(bSensValue);
  
  rLEDValue = rSensValue/4;
  gLEDValue = gSensValue/4;
  bLEDValue = bSensValue/4;
  
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(rLEDValue);
  Serial.print("\t Green: ");
  Serial.print(gLEDValue);
  Serial.print("\t Blue: ");
  Serial.print(bLEDValue);
  
  analogWrite(rLEDPin, rLEDValue);
  analogWrite(gLEDPin, gLEDValue);
  analogWrite(bLEDPin, bLEDValue);
}
