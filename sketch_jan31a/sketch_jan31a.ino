int ledPin = 9;
int buttonPin = 11;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop(){
  if (digitalRead(buttonPin) == HIGH) {
    analogWrite(ledPin, 10);
    delay(5000);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
