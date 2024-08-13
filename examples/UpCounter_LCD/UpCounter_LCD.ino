#include <Counter.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

//Digital Input Declaration 
const int s1 = A0;
const int s2 = A1;
const int s3 = A2;
const int s4 = A3;
const int s5 = 2;
const int s6 = 3;
const int s7 = 4;
const int s8 = 5;

//Digital Output Declaration
const int r1 = 13;
const int r2 = 12;
const int r3 = 11;
const int r4 = 6;
const int r5 = 7;
const int r6 = 8;
const int r7 = 9;
const int r8 = 10;

//Analog Input Declaration
const int a1 = A6;
const int a2 = A7;

int A_1;
int A_2;

//Inputs Boolean variable declaration
bool S1;
bool S2;
bool S3;
bool S4;
bool S5;
bool S6;
bool S7;
bool S8;

//Outputs Boolean variable declaration
bool R1;
bool R2;
bool R3;
bool R4;
bool R5;
bool R6;
bool R7;
bool R8;

int I1;

//Call the Class and Assign Object for TimerS
Count C1;

void setup() {
  IO(); // call the inputs and output pin configuration
  lcd.init();
  lcd.backlight();
}

void loop() {

  input();

  //Counter parameter settings
  C1.CTU(C1.CU, C1.RES, C1.PV = 5, C1.CV, C1.DN);

    lcd.setCursor(0,0);
    lcd.print("PV: ");
    lcd.setCursor(4,0);
    lcd.print(C1.PV);

    lcd.setCursor(7,0);
    lcd.print("CV: ");
    lcd.setCursor(11,0);
    lcd.print(C1.CV);

    if (S1) {//increment the counter value
      C1.CU = true;
    } else {
      C1.CU = false;
    }

    if (S2) {//Reset Counter
      C1.RES = true;
    } else {
      C1.RES = false;
    }

    if (C1.DN){ //Counter Done
      R1 = true;
      lcd.setCursor(0,1);
      lcd.print("DN: ON ");
    }
    else {
      R1 = false;
      lcd.setCursor(0,1);
      lcd.print("DN: OFF");
    }
    
  output();

}

//read input state with debounce
void input() {
S1 = !digitalRead(s1);
S2 = !digitalRead(s2);
S3 = !digitalRead(s3);
S4 = !digitalRead(s4);
S5 = !digitalRead(s5);
S6 = !digitalRead(s6);
S7 = !digitalRead(s7);
S8 = !digitalRead(s8);

A_1 = analogRead(a1);
A_2 = analogRead(a2);
}

//Update output pin status
void output() {
  digitalWrite(r1, R1);  
  digitalWrite(r2, R2);  
  digitalWrite(r3, R3);  
  digitalWrite(r4, R4);  
  digitalWrite(r5, R5);  
  digitalWrite(r6, R6);  
  digitalWrite(r7, R7);  
  digitalWrite(r8, R8);  
}

//configure input and output pins
void IO() {
//set pins to inputs 
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  pinMode(s8, INPUT);

//set pins to outputs
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);

//Initialized the output pins to zero
  digitalWrite(r1, false);  
  digitalWrite(r2, false);  
  digitalWrite(r3, false);  
  digitalWrite(r4, false);  
  digitalWrite(r5, false);  
  digitalWrite(r6, false);  
  digitalWrite(r7, false);  
  digitalWrite(r8, false);  

}