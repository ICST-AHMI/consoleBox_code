// SERIAL PARSER **********************************

int stop = 0;
int VarSign = 1;
int SerIn = -1;          // incoming byte from serial RX
long VarN[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };      // number array
int PosN = -1;       // index counter
char VarHandlerChar = '@';       //

void SerialParser(void) {
  while (Serial.available()) {
    SerIn = '@';
    SerIn = Serial.read();
    // debugging CODE
    // Serial.print(' ');
    // Serial.print(SerIn);
    if ((SerIn >= 65) && (SerIn <= 90)) {          // if ASCII 'A' - 'Z'
      VarHandlerChar = SerIn;  
      for (PosN = 0; PosN < 9; PosN++) {           // clean up
        VarN[PosN] =  0;                           // reset Var array
      }  
      PosN = -1;                              
    }
    if (SerIn == 45) {
      VarSign = -1;
    }
    if ((SerIn >= 48) && (SerIn <= 57)) {          // if ASCII numeric '0' - '9'
      VarN[PosN] = VarN[PosN] * 10 + (SerIn - 48);
    }
    if (SerIn == ' ') {                            // if ASCII " " detected
      if (PosN > -1) {
        VarN[PosN] = VarSign * VarN[PosN];           // assign sign
        VarSign = 1;
      }
      PosN++;
    }
    if (SerIn == 33 || SerIn == 10 || SerIn == 13) {  // '!' or CR or LF ends all this spooky things ...
      VarN[PosN] = VarSign * VarN[PosN];           // assign sign
      VarSign = 1;
      callHandler();                               // Call funktion by first Char
    }   // IfEND CR spooky things
  }
}

void callHandler(){
  /*
  Serial.print("debug");
  for (int  i = 0; i < PosN; i++) {
    Serial.print(' ');
    Serial.print(VarN[i]);
  }
  Serial.println(" !");
  */

  for (int  i = 0; i < PosN; i++) {
    digitalWrite(8 + i, VarN[i]); 
  }
}

