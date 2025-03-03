#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define COL_NUM			4
#define ROW_NUM			4


#define KEYPAD_VALUES			{ {'7','8','9','+'},\
								  {'4','5','6','-'},\
								  {'1','2','3','x'},\
								  {'c','0','=','/'}  }



#define C1_PORT			DIO_u8GROUP_D
#define C1_PIN			DIO_u8PIN3

#define C2_PORT			DIO_u8GROUP_D
#define C2_PIN			DIO_u8PIN4

#define C3_PORT			DIO_u8GROUP_D
#define C3_PIN			DIO_u8PIN5

#define C4_PORT			DIO_u8GROUP_D
#define C4_PIN			DIO_u8PIN6



#define R1_PORT			DIO_u8GROUP_C
#define R1_PIN			DIO_u8PIN2

#define R2_PORT			DIO_u8GROUP_C
#define R2_PIN			DIO_u8PIN3

#define R3_PORT			DIO_u8GROUP_C
#define R3_PIN			DIO_u8PIN4

#define R4_PORT			DIO_u8GROUP_C
#define R4_PIN			DIO_u8PIN5



#endif /* KEYPAD_CONFIG_H_ */
