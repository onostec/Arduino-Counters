# Simple Counter Library based on PLC Timers

## Counter Options

CTU = Up Counter

CTD = Down Counter

CTY = Cyclic Counter

Counter Description
Up Counter – CTU
The CTU counter requires CU (Enable) to be True to increase CV (Counter Value) by one. The DN (Done Bit) becomes True when CV (Counter Value) = PV (Preset Value). When DN is True, CV will stop increasing. If RES (RESET) is True, CV and DN are set to zero which will allow the counter to start counting again.

Down Counter – CTD
The CTD counter requires CD (Enable) to be True to decrease CV (Counter Value) from PV (Preset Value) by one. DN (Done Bit) becomes True when CV (Counter Value) = 0. When DN is True, CV will stop decreasing. If RES (RESET) is True, CV is set to PV and DN is set to zero which allow the counter to start counting again.

Up-Down Counter – CTU & CTD
The Up-Down Counter requires CU (Enable) to be True to increase CV (Counter Value) by one and CD (Enable) to be True to decrease CV (Counter Value) by one on the same counter object. The DN (Done Bit) becomes True when CV (Counter Value) = PV (Preset Value) or when CV (Counter Value) = 0. When DN is True, CV will stop increasing or decreasing. If RES (RESET) is True, CV and DN are set to zero which will allow the counter to start counting again.

Cyclic Counter – CTY
The CTY counter requires CU (Enable) to be True to increase CV (Counter Value) by one. The DN (Done Bit) becomes True when CV (Counter Value) = PV (Preset Value). When CV (Counter Value) > PV (Preset Value) CV will become zero and continue to count, while DN will change to False. If RES (RESET) is True, CV and DN are set to zero.

How to use the Counters
Call and assign an object for each counter you intend to use before the Setup and Loop function.
Count C1;
-	Count is the Class
-	C1 is the Object
The functions within the Class can then be called and used in the Loop function.
	C1.CTU(“Parameters HERE”)
	C1.CTD(“Parameters HERE”)
	C1.CTY(“Parameters HERE”)
The parameters can be used outside the function by using the class object. Do not write to the read parameters.
	C1.CU = true; //Enable CTU or CTY C1 counter
	C1.CD = true; //Reset CTD, CTU or CTY C1 counter
	C1.RES= true; //Enable CTU C1 counter
	C1.PV = 5; //Set C1 counter Preset
	Bool result_DN =  C1.DN; //Read C1 counter Done Status
	Unsigned long result_CV = C1.CV; //Read C1 counter value

The counter parameters are
1.	ENABLE (CU)/(CD)
2.	RESET (RES)
3.	PRESET VALUE(PV)
4.	COUNTER DONE (DN)
5.	COUNTER VALUE (CV)
