#include <Arduino.h>
#include <Motor.h>



void ESC_init(ESC_TypeDef* esc, uint16_t opFreq, uint32_t autoRld, float per)
 {
	(esc->THROTTLE_SIG) = 0; // setting throttle sig to a value so that I know its value
	(esc->OP_FREQ) = opFreq;
	(esc->AUTO_RLD) = autoRld; //1920000
	(esc->PER) = per; //1.0/50
	};

int ESC_updateDtyCycle(ESC_TypeDef* esc, float throttle_Sig) {

	if( throttle_Sig > -100 || throttle_Sig < 100 ) {
 			printf("Within range");
 	}	else if( throttle_Sig < -100 ) {
 			throttle_Sig = -100;
 	}	else if( throttle_Sig > 100) {
 			throttle_Sig = 100;
 	}	else {
 			printf("Houston	we have a problem");
 	}

 	printf("The duty cycle is: %d\n", throttle_Sig);

	esc->THROTTLE_SIG = throttle_Sig; //example line of code to set throttle
	// -100 corresponds to 1100 and 100 corresponds to 1900
	// I need to scale the values from -100 and 100 to the range of 1100 to 1900
	float onTime = (esc->STOP_SIG + throttle_Sig*4)*(1.0/1000); // This line gives us the "on-time" of the ESC in seconds
	float dtyCycle = (onTime/esc->PER)*(1.0/10); // Calculates the duty cycle
	// line of math = threshold (thrsh); auto-reload - (duty cycle * auto-reload)
	float thrsh = esc->AUTO_RLD - dtyCycle*esc->AUTO_RLD;
	*(esc->ESC_TMRCH_CCR) = thrsh;
	return thrsh;
}