/*
  The MIT License (MIT)
  Copyright (c) 2024 OnosTech
  Permission is hereby granted, free of charge, to any person obtaining a copy of
  this software and associated documentation files (the "Software"), to deal in
  the Software without restriction, including without limitation the rights to
  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  the Software, and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
Please see the README and Examples on how to use
*/

#ifndef Counter
#define Counter

#include "Arduino.h"

class Count{
public:

//Function in the Class pass by Reference
//CTU Counter
void CTU(bool CU, bool RES, unsigned long PV, unsigned long &CV, bool &DN);
//CTD Counter
void CTD(bool CD, bool RES, unsigned long PV, unsigned long &CV, bool &DN);
//CTY Counter
void CTY(bool CY, bool RES, unsigned long PV, unsigned long &CV, bool &DN);

//Counter Parameters
bool RES;    //Reset Counter 
bool DN;     //Counter DONE
bool CU;     //Counter Count Up Bit
bool CD;     //Counter Count Down Bit
unsigned long CV; //Counter Value
unsigned long PV;  //Set Preset Value

private:
//CTU Counter Function
bool CUState;
bool CDState;
bool CYState;
bool CUDState;
bool PVState;

};


#endif