// when the button is pressed
// display a different level of brightness

int switchPin = 8;
int ledPin = 11;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledLevel = 0;

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
    ledLevel = (ledLevel + 51); 
  }

  if (ledLevel > 255){
    ledLevel = 0;
  }
  
  lastButton = currentButton;
  analogWrite (ledPin, ledLevel);
  
}
