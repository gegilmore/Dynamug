#include <Arduino.h>
#include <Motor.h>
#include <Servo.h>



Motor::Motor(byte in_pin, uint16_t fwd_sig, uint16_t Reverse, uint16_t stop)
 {
    Servo SERVO;
    SERVO.attach(in_pin);
    Motor->SERVO_PIN = in_pin;
    Motor->FWD_SIG = fwd_sig;
    Motor->REV_SIG = Reverse;
    Motor->STOP_SIG = stop;

	


}

void Motor::updateMotor(uint16_t throttle)
{
	uint16_t finalmicro = 0;
	
	Servo servo;
    servo.attach(Motor -> SERVO_PIN);

	if( throttle > -100 || throttle < 100 ) 
    {
 			printf("Within range");
 	}	
    else if( throttle < -100 ) 
    {
 			throttle = -100;
			finalmicro = Motor->REV_SIG;
 	}	
    else if( throttle > 100) 
    {
 			throttle = 100;
			finalmicro = Motor->FWD_SIG;
 	}
	else if( throttle > 0) 
    {
			
			finalmicro = (Motor->FWD_SIG - Motor->STOP_SIG)*(throttle/100) + Motor->STOP_SIG);
 	}
	else if( throttle < 0) 
    {
			
			finalmicro = (( Motor->STOP_SIG - Motor->REV_SIG)*(throttle/100) + Motor->REV_SIG);
 	}
	 else if( throttle = 0) 
    {
			
			finalmicro = Motor->STOP_SIG;
 	}	
    else  
    {
 			printf("Houston	we have a problem");
 	}

 	//printf("The duty cycle is: %d\n", throttle_Sig);

	SERVO.writeMicroseconds(finalmicro);
	
	//esc->THROTTLE_SIG = throttle_Sig; //example line of code to set throttle
	// -100 corresponds to 1100 and 100 corresponds to 1900
	// I need to scale the values from -100 and 100 to the range of 1100 to 1900
	//float onTime = (esc->STOP_SIG + throttle_Sig*4)*(1.0/1000); // This line gives us the "on-time" of the ESC in seconds
	//float dtyCycle = (onTime/esc->PER)*(1.0/10); // Calculates the duty cycle
	// line of math = threshold (thrsh); auto-reload - (duty cycle * auto-reload)
	//float thrsh = esc->AUTO_RLD - dtyCycle*esc->AUTO_RLD;
	//*(esc->ESC_TMRCH_CCR) = thrsh;
	return;
}