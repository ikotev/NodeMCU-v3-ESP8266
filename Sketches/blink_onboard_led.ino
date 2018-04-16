int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);     
}

void loop() {
  digitalWrite(ledPin, LOW); 
  delay(300);               
  digitalWrite(ledPin, HIGH);
  delay(3000);     
}
