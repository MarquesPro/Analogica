const int potPin = A0; 
const int ledPin = 3; 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int potValue = analogRead(potPin);
  int breathTime = map(potValue, 0, 1023, 0, 4000);
  int fadeInTime = breathTime / 2; 
  int fadeOutTime = breathTime / 2; 
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(fadeInTime / 255); 
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(fadeOutTime / 255); 
  }
}
