#define RCCahb1enR *((unsigned volatile int*)0x40023830)
#define GPIODOdr *((unsigned volatile int*)0x40020c14)
#define GPIODModr *((unsigned volatile int*)0x40020c00)
#define GPIOD 1<<3
#define GPIODPBlue 1<<30
#define GPIODPGreen 1<<24
#define GPIODPBlueLedOn 1<<15
#define GPIODPBlueLedoff 0<<15
#define GPIODPGreenLedOn 1<<12
#define GPIODPGreenLedoff ~(1<<12)

void init_leds(){
	RCCahb1enR =GPIOD;
	GPIODModr=GPIODPBlue;
	GPIODModr |=GPIODPGreen;
}
void name(){
	turn_name_on();
	delay();
	turn_name_off();
	delay();
}
void surname(){
	turn_surname_on();
	delay();
	turn_surname_off();
	delay();
}
void turn_surname_on(){
	GPIODOdr =GPIODPBlueLedOn;

}
void turn_surname_off(){
	GPIODOdr =GPIODPBlueLedoff;

}
void turn_name_on(){
	GPIODOdr |=GPIODPGreenLedOn;

}
void turn_name_off(){
	GPIODOdr &=GPIODPGreenLedoff;

}
void delay(){
	int delay0 = 0x000FFFFF; //delay loop
	while (delay0--){
		}
}


int main(){
	init_leds();

	int i=0;

	while(i<6){
		name();
		i++;
	}
	i = 0;
	while (i<5){
		surname();
		i++;
	}

	return 0;


}
























