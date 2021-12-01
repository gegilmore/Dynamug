#include <Arduino.h>
#include <Motor.h>
#include <Servo.h>



Motor::Motor(byte in_pin, uint16_t fwd_sig, uint16_t Reverse, uint16_t stop)
 {
    Servo servo;
    servo.attach(in_pin);
    Motor -> SERVO_PIN = in_pin;
    Motor -> FWD_SIG = fwd_sig;
    Motor -> REV_SIG = Reverse;
    Motor -> STOP_SIG = stop;

	(esc->THROTTLE_SIG) = 0; // setting throttle sig to a value so that I know its value
	(esc->OP_FREQ) = opFreq;
	(esc->AUTO_RLD) = autoRld; //1920000
	(esc->PER) = per; //1.0/50

}

void Motor::updateMotor(uint16_t throttle)
{

	if( throttle > -100 || throttle < 100 ) 
    {
 			printf("Within range");
 	}	
    else if( throttle < -100 ) 
    {
 			throttle = -100;
 	}	
    else if( throttle > 100) 
    {
 			throttle = 100;
 	}	
    else  
    {
 			printf("Houston	we have a problem");
 	}

 	//printf("The duty cycle is: %d\n", throttle_Sig);

    

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