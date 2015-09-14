/*
  BlackBox Firmware 0.1
  by Martin Froehlich
  
  (c) ICST.net
 */
 
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int piano = 8;
int greenLight = 9;
int redRoundLight = 10;
int redSquareLight = 11;
int orangeLight = 12;

int buttonSquareRed = 2;
int buttonRoundRed = 3;
int buttonRoundOrange = 4;
int buttonRoundGreen = 5;
int switchLeft = 6;
int switchRight = 7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(piano, OUTPUT);     
  pinMode(greenLight, OUTPUT);     
  pinMode(redRoundLight, OUTPUT);     
  pinMode(redSquareLight, OUTPUT);     
  pinMode(orangeLight, OUTPUT);   
  
  pinMode(buttonSquareRed, INPUT);     
  pinMode(buttonRoundRed, INPUT);     
  pinMode(buttonRoundOrange, INPUT);     
  pinMode(buttonRoundGreen, INPUT);     
  pinMode(switchLeft, INPUT);     
  pinMode(switchRight, INPUT);  

  Serial.begin(9600);
  
}

int redSqState = 0;
int redRndState = 0;
int orangeRndState = 0;
int greenRndState = 0;
int switchState = 0;

boolean stateChange = false;
boolean debounceChange = false;
// the loop routine runs over and over again forever:
void loop() {
  // read the state of the pushbutton value:

  int switchLR = digitalRead(switchLeft) + digitalRead(switchRight) * 2;
  if(switchLR != switchState ){
    stateChange = true;
    switchState = switchLR;
  }
  if(digitalRead(buttonSquareRed) != redSqState){
    stateChange = true;
    redSqState = 1 - redSqState;
  }
  if(digitalRead(buttonRoundRed) != redRndState){
    stateChange = true;
    redRndState = 1 - redRndState;
  }
  if(digitalRead(buttonRoundOrange) != orangeRndState){
    stateChange = true;
    orangeRndState = 1 - orangeRndState;
  }
  if(digitalRead(buttonRoundGreen) != greenRndState){
    stateChange = true;
    greenRndState = 1 - greenRndState;
  }
    
  if(stateChange){
    lastDebounceTime = millis();
    stateChange = false; 
    debounceChange = true;
  }

  if (debounceChange && (millis() - lastDebounceTime) > debounceDelay) {
    Serial.print(switchState);
    Serial.print(" ");
    Serial.print(greenRndState);
    Serial.print(" ");
    Serial.print(redRndState);
    Serial.print(" ");
    Serial.print(redSqState);
    Serial.print(" ");
    Serial.print(orangeRndState);
    Serial.println("!");
    debounceChange = false;
  }
 
 SerialParser();
 
}
  
