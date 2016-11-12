
const int pResistor = A0;
const int ledPin = 9;

int value;
int ledBrightness;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(pResistor, INPUT);
 Serial.begin(9600);
}

void loop() {
  value = analogRead(pResistor);
  Serial.println(value);

  ledBrightness = map(value, 1023, 0, 0, 255);
  analogWrite(ledPin, ledBrightness);

}
