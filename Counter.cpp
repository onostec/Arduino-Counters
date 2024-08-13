#include "Arduino.h"
#include "Counter.h"

//Counter CTU Function Returns Done Bit when Elapsed Count = Preset Count
void Count::CTU(bool CU, bool RES, unsigned long PV, unsigned long &CV, bool &DN){ //Returning Data using Reference

CUDState = 1;
if (CU == 1 && CUState == 0) { //Counter Enabled
	if (DN == 0) {
        CV++;
		if (CV > PV) {
			CV = 0;
		}
    } 
    if (CV >= PV && PV > 0) { //Count is done activate Done (DN) bit
        DN = 1;
    }
	CUState = 1;
}

if (CU == 0) {
	CUState = 0;
}

if (RES == 1) { //Reset Counter
    CUState = 0;
    DN = 0;
    CV = 0;
}

}

//Counter CTD Function Returns Done Bit when Elapsed Count = Preset Count
void Count::CTD(bool CD, bool RES, unsigned long PV, unsigned long &CV, bool &DN){ //Returning Data using Reference

if (CUDState ==0 && PVState == 0){
	CV = PV;
	PVState = 1;
}

if (CD == 1 && CDState == 0) { //Counter Enabled
	if (DN == 0 && CV > 0) {
        CV--;
    } 
    if (CV == 0) { //Count is done activate Done (DN) bit
        DN = 1;
    }
	CDState = 1;
}

if (CD == 0) {
	CDState = 0;
}
  
if (RES == 1) { //Reset Counter
    CDState = 0;
    DN = 0;
    CV = PV;
	if (CUDState == 1){
		CV = 0;
	}
}

}

//Counter CTY Function Returns Done Bit when Elapsed Count = Preset Count
void Count::CTY(bool CY, bool RES, unsigned long PV, unsigned long &CV, bool &DN){ //Returning Data using Reference

if (CY == 1 && CYState == 0) { //Counter Enabled
    DN = 0;    
	if (DN == 0) {
        CV++;
		if (CV > PV) {
			CV = 0;
		}
    } 
    if (CV == PV) { //Count is done activate Done (DN) bit
        DN = 1;
    }
	CYState = 1;
}
  
if (CY == 0) {
	CYState = 0;
}
  
if (RES == 1) { //Reset Counter
    CYState = 0;
    DN = 0;
    CV = 0;
}

}

