const char DATA[] = {3,4,5,6,7,8,9,10};
const char CLOCK = 11;

void setup() {
  // Read data lines
  for(int n = 0; n < 8; n += 1) {
    pinMode(DATA[n], INPUT);
  }
  pinMode(CLOCK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING);
  Serial.begin(57600);
}

void onClock() {
  for(int n = 0; n < 8; n +=1) {
    int bit = digitalRead(DATA[n]) ? 1 : 0;
    Serial.print(bit);
  }
  Serial.println();
}

void loop() {

}
