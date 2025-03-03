#ifndef APP_MAIN_CONFIG_H_
#define APP_MAIN_CONFIG_H_

#define TRUE									 1
#define FALSE									 0
#define NULL_CHARACTER 							'\0'
#define NULL_CHARACTER_COUNT					 1

#define LCD_KEYPAD_USER	   					 	 0  // Keypad
#define ADMIN_PRIORITY 					   		 1	//admin
#define REMOTED_USER						   	 2	//dont have exceptin
#define PROMOTED_USER						 	 3 	//have exception above keypad user

#define MAX_NO_OF_USERS							 4
#define MAX_NO_OF_LETTERS						 4
/**********************************EEPROM Used Addresses***********************************/
#define SAVED_INITIAL_PROGRAM_STATE_ADDRESS	 0x00
#define	SAVED_ADMIN_INFO_ADDRESS				 0X01
#define NO_OF_REGISTERED_USERS_ADDRESS 			 0x11
#define	SAVED_USERS_INFO_ADDRESS				 0x12
/**********************************Program States ***********************************/
#define FIRST_TIME_USE_STATE 					 0xff
#define LOAD_LOGIN_SYSTEM_DATABASE_STATE		 0x00
#define IDLE_STATE 								 0x07
#define REMOTED_SYSTEM_LOGIN_PAGE_STATE 		 0X02
#define LCD_KEYPAD_LOGIN_PAGE_STATE				 0X03
#define REMOTED_SYSTEM_MENU_STATE				 0x04
#define LCD_KEYPAD_MENU_STATE 					 0x05
#define BLOCKING_STATE 							 0x06



#define State_ROOM_1							 1
#define State_ROOM_2							 2
#define State_ROOM_3							 3
#define State_ROOM_4							 4
#define State_Dimmer							 5
#define State_Air_Cond							 7
#define State_Door								 6


#define MAIN_MENU  0

#define ROOM1_LED_TOGGLE 1
#define ROOM2_LED_TOGGLE 2
#define ROOM3_LED_TOGGLE 3
#define ROOM4_LED_TOGGLE 4


#define ADD_USER_COMMAND	6
#define REMOVE_USER_COMMAND	7
#define DIMMER_MENU  8
#define AIR_COND_MENU  9
#define DOOR_MENU  10
#define LOG_OUT_CHOICE 11
#define DIMMER   12
#define OPEN_DOOR_COMMAND 13
#define CLOSE_DOOR_COMMAND 14
#define PRIORITIES_MENU 15
#define MORE_MENU    16
#define OPEN_AirCond_COMMAND					 16
#define CLOSE_AirCond_COMMAND					 17
#define AUTO_AirCond_COMMAND					18
typedef struct {
	u8 UserName[MAX_NO_OF_LETTERS+NULL_CHARACTER_COUNT];
	u8 Password[MAX_NO_OF_LETTERS+NULL_CHARACTER_COUNT];
	u8 	User_Priority;
}User_t;


#endif /* APP_MAIN_CONFIG_H_ */
