/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
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

int buttonState = 0;         // variable for reading the pushbutton status

// the loop routine runs over and over again forever:
void loop() {
    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonSquareRed);

  Serial.println(buttonState); 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(redSquareLight, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(redSquareLight, LOW); 
  }

/*
  digitalWrite(piano, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(greenLight, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(redRoundLight, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(redSquareLight, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(orangeLight, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);               // wait for a second
  digitalWrite(piano, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(greenLight, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(redRoundLight, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(redSquareLight, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(orangeLight, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(5000);               // wait for a second
 */
}
