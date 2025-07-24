#include "ULTRA_SONIC.h"

// ------------------- Globals -------------------
static volatile uint16 g_rising_time = 0;
static volatile uint16 g_falling_time = 0;
static volatile uint8 g_edge_flag = 0;

// ------------------- INIT -------------------
void Ultrasonic_init(void) {
	GPIO_vSetPinDirection(Port_D, Pin_7, Pin_Output); // Trigger pin
	GPIO_vSetPinDirection(Port_D, Pin_6, Pin_Input); // Echo pin

	TIMER1_vidINCAPRissing();         // Start with rising edge
	TIMER1_vidInit();                 // Use NORMAL mode (set in config)
	TIMER1_vidCAPInterruptEnable();   // Enable ICU interrupt
	TIMER1_vidStart();                // Start Timer1

	ICU_setCallBack(Ultrasonic_edgeProcessing);
}

// ------------------- TRIGGER -------------------
void Ultrasonic_Trigger(void) {
	GPIO_vSetPinValue(Port_D, Pin_7, Pin_High);  // Trigger = High
	_delay_us(10);                               // 10 microseconds
	GPIO_vSetPinValue(Port_D, Pin_7, Pin_Low);   // Trigger = Low
}

// ------------------- READ DISTANCE -------------------
uint16 Ultrasonic_readDistance(void) {
//	Ultrasonic_Trigger();
//
//	while (g_edge_flag != 0);  // Wait until both edges are captured
//
//	uint16 time = g_falling_time - g_rising_time;
//	uint16 distance_cm = (uint16)(time * 0.0272);  // Approx. for F_CPU=8MHz, Prescaler=8
//
//	return distance_cm;

	// unit testing
	Ultrasonic_Trigger();

	uint32 timeout = 50000;
	while (g_edge_flag != 0 && timeout--) {
		_delay_us(1);
	}

	if (timeout == 0) {
		return 0xFFFF; // خطأ أو timeout
	}

	uint16 time = g_falling_time - g_rising_time;
	return (uint16)(time * 0.0272);
}

// ------------------- ICU ISR Callback -------------------
void Ultrasonic_edgeProcessing(void) {
	if (g_edge_flag == 0) {
		g_rising_time = TIMER1_u16INCAPRead();
		TIMER1_vidINCAPFalling();
		g_edge_flag = 1;
	} else {
		g_falling_time = TIMER1_u16INCAPRead();
		TIMER1_vidINCAPRissing();
		g_edge_flag = 0;
	}
}
