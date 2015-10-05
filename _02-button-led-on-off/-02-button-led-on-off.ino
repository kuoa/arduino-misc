// switch the led on and off
// debounce it

int switchPin = 8;
int ledPin = 13;

boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

boolean debounce (boolean prev){

  boolean current = digitalRead(switchPin);

  if (prev != current){
    delay (5);
    current = digitalRead(switchPin);
  }

  return current;  
}


void setup() {

  pinMode (switchPin, INPUT);
  pinMode (ledPin, OUTPUT);
  
}

void loop() {
  currentButton = debounce (lastButton);

  if (lastButton == LOW && currentButton == HIGH){
    ledOn = !ledOn;  
  }

  lastButton = currentButton;
  digitalWrite (ledPin, ledOn);
  
}
