int notes[] = {262,294,330,349,392};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyRawValue = analogRead(A0);
  int keyVal = map(keyRawValue,0,1023,0,1000000);
  
  Serial.println(keyVal);
  
  if (keyVal == 16960) {
    tone(8,notes[0]);
  }
  else if (keyVal == -5481 || keyVal == -6459 || keyVal == -7436) {
    tone(8,notes[1]);
  }
  else if (keyVal == -18912 || keyVal == -19890 || keyVal == -17935 || keyVal == -20867) {
    tone(8,notes[2]);
  }
  else if (keyVal == 8797 || keyVal == 9775 || keyVal == 5865 || keyVal == 6842 || keyVal == 7820) {
    tone(8,notes[3]);
  }
  else if (keyVal >= 1 && keyVal <= 1000) {
    tone(8,notes[4]);
    delay(1000);
  }
  else{
    noTone(8);
  }
}
