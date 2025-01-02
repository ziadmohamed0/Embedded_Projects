
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/bit_math.h"


#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/SPI/SPI_int.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/EEPROM/EPROM_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/Keypad/Keypad_int.h"


#include "main_config.h"
#include "LoginSystem.h"

#include <util/delay.h>

u8 LoginSystem_u8AdminOnlineFlag = 0;
u8 LoginSystem_u8PromotedUserOnlineFlag = 0;
u8 ShowToUser = MAIN_MENU;
u8 Program_Status_Flag = 0;
u8 Blocking_Flag=FALSE;

volatile void Button_Pressed_Interrupt();  //The function that's executed on the EXT INT ISR interrupt When a button is pressed Which Indicates that a LCD_KEYPAD user wants to initiate a login attempt,So it switch the program state into the "LCD_KEYPAD_LOGIN_PAGE_STATE"

//Our Program is divided into several State "Finite State Machine"
//These States are explained as you go through the code 

int main (void)
{
	
/*************************************************************************************************************/
/*******************************************INITIALIZATIONS***************************************************/
/*************************************************************************************************************/
DIO_enuInit();
SPI_vidInit();
UART_enuUART_Init();

LCD_enuInit();
Keypad_enuInit();
EXTI_enuInit();
	
EXTI_enuCallBack((volatile void (*) (void))Button_Pressed_Interrupt);

/************************************************************************************************************/
/***********************************DEVICE OUTPUT CONFIGURATION**********************************************/
/************************************************************************************************************/

DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN1,DIO_u8OUTPUT); //UART Transmit Enable Pin output
DIO_enuSetPinDirection(DIO_u8GROUP_C,DIO_u8PIN0,DIO_u8OUTPUT); // Blocking mode pin
__asm("sei");	// GIE Enable
	
/************************************************************************************************************/
/**************************************VARIABLE DECLARATIONS*************************************************/
/************************************************************************************************************/

User_t LoginSystem_strAdmin;
User_t LoginSystem_AstrUsers[MAX_NO_OF_USERS];
u8 LoginSystem_NumOfRegisteredUsers=0;
u8 LoginSystem_Au8Username[MAX_NO_OF_LETTERS+NULL_CHARACTER_COUNT];
u8 LoginSystem_Au8Password[MAX_NO_OF_LETTERS+NULL_CHARACTER_COUNT];

u8 Keypad_Pressed_Key;
u8 Current_State = 0;
u8 On_Devices = 0;
u8 UART_CHOICE;
u8 Dimmer_Percentage;
u8 Dimmer_Percentage_Tens;
u8 Dimmer_Percentage_Ones;
u8 LoginSystem_u8TrialsLeft =3;

/************************************************************************************************************/
/********************************************WELCOME PAGE****************************************************/
/************************************************************************************************************/
	
	LCD_enuDisplayString("Welcome To Smart");
	LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
	LCD_enuDisplayString("Home !");
	EEPROM_ui8ReadByteFromAddress(SAVED_INITIAL_PROGRAM_STATE_ADDRESS,&Program_Status_Flag);
	_delay_ms (700);
	LCD_enuClearDisplay();
/************************************************************************************FIRST_TIME_USE_STATE*********************************************************************************/
/************************************************************First State of The Program In Case of First Time Use of The smart Home******************************************************/
/*****************************************************************It Registers The Admin For First Time and Save it in EEPROM***********************************************************/
	
			if (Program_Status_Flag == FIRST_TIME_USE_STATE)
			{

				EEPROM_vWriteByteToAddress(NO_OF_REGISTERED_USERS_ADDRESS,LoginSystem_NumOfRegisteredUsers);
				_delay_ms(50);
				LCD_enuDisplayString("For First Time");
				LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
				LCD_enuDisplayString("Use");
				_delay_ms(700);
				LCD_enuClearDisplay();
				LCD_enuDisplayString("Register Admin");
				LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
				LCD_enuDisplayString("on Keypad");
				_delay_ms(700);
				LoginSystem_enuGetDataFromUserByKeypad(LoginSystem_strAdmin.UserName, LoginSystem_strAdmin.Password);
				LoginSystem_strAdmin.User_Priority = ADMIN_PRIORITY;
				
				
				EEPROM_vWriteBlockToAddress(SAVED_ADMIN_INFO_ADDRESS ,LoginSystem_strAdmin.UserName , MAX_NO_OF_LETTERS);
				_delay_ms(50);
				EEPROM_vWriteBlockToAddress(SAVED_ADMIN_INFO_ADDRESS + MAX_NO_OF_LETTERS ,LoginSystem_strAdmin.Password , MAX_NO_OF_LETTERS);
				_delay_ms(50);

				EEPROM_vWriteByteToAddress(SAVED_INITIAL_PROGRAM_STATE_ADDRESS,LOAD_LOGIN_SYSTEM_DATABASE_STATE);
				_delay_ms(50);
	
				LCD_enuClearDisplay();
				LCD_enuDisplayString("Saved");
				LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
				LCD_enuDisplayString("Successfully");
				_delay_ms(700);
				LCD_enuClearDisplay();
				
				Program_Status_Flag = IDLE_STATE;

			}//end of the FIRST_TIME_USE_STATE
			
/********************************************************************************LOAD_LOGIN_SYSTEM_DATABASE_STATE*************************************************************************/
/********************************************************First State of The Program if it's not the First Time Use of The smart Home*****************************************************/
/****************************************************It Loads the Usernames and Passwords of The ADMIN and Registered Users from the EEPROM*********************************************/

			else if (Program_Status_Flag == LOAD_LOGIN_SYSTEM_DATABASE_STATE)
			{
				
				EEPROM_ui8ReadByteFromAddress(NO_OF_REGISTERED_USERS_ADDRESS,&LoginSystem_NumOfRegisteredUsers);
				_delay_ms(50);
				

				EEPROM_vReadBlockFromAddress(SAVED_ADMIN_INFO_ADDRESS,LoginSystem_strAdmin.UserName,MAX_NO_OF_LETTERS);
				LoginSystem_strAdmin.UserName[MAX_NO_OF_LETTERS] = NULL_CHARACTER;
				_delay_ms(50);
				EEPROM_vReadBlockFromAddress(SAVED_ADMIN_INFO_ADDRESS + MAX_NO_OF_LETTERS,LoginSystem_strAdmin.Password,MAX_NO_OF_LETTERS);
				LoginSystem_strAdmin.Password[MAX_NO_OF_LETTERS] = NULL_CHARACTER;
				_delay_ms(50);
				
				LoginSystem_strAdmin.User_Priority=ADMIN_PRIORITY;
				_delay_ms(50);

				u16 Local_u16UserAddress;
				for (u8 Local_u8Iterator=0; Local_u8Iterator < LoginSystem_NumOfRegisteredUsers; Local_u8Iterator++)
				{
					Local_u16UserAddress = SAVED_USERS_INFO_ADDRESS +Local_u8Iterator*(2* MAX_NO_OF_LETTERS+1);
					EEPROM_vReadBlockFromAddress(Local_u16UserAddress,&LoginSystem_AstrUsers[Local_u8Iterator].UserName,MAX_NO_OF_LETTERS);
					_delay_ms(50);

					EEPROM_vReadBlockFromAddress(Local_u16UserAddress + MAX_NO_OF_LETTERS,&LoginSystem_AstrUsers[Local_u8Iterator].Password,MAX_NO_OF_LETTERS);
					_delay_ms(50);
					EEPROM_ui8ReadByteFromAddress(Local_u16UserAddress + 2*MAX_NO_OF_LETTERS,&LoginSystem_AstrUsers[Local_u8Iterator].User_Priority);
					_delay_ms(50);
					LoginSystem_AstrUsers[Local_u8Iterator].UserName[MAX_NO_OF_LETTERS] = NULL_CHARACTER;
					LoginSystem_AstrUsers[Local_u8Iterator].Password[MAX_NO_OF_LETTERS] = NULL_CHARACTER;
				}
				

				Program_Status_Flag = IDLE_STATE;
			}//end of the LOAD_LOGIN_SYSTEM_DATABASE_STATE
			
			
			
		
	while (1)
	{
		
/************************************************************************************IDLE_STATE********************************************************************************************/
/***********************************Second State of The Program: The Program stays in this state as long as the LCD_Keypad System and The Remoted System aren't used**********************/
/**************************************************************It Displays The Currently Running Device on The LCD***********************************************************************/
	if (Program_Status_Flag == IDLE_STATE)
	{
	UART_enuSendString("Press Any Key To Start A Login Attempt\r\n");	
	LCD_enuClearDisplay();
	u8 Local_u8Iterator = 1;
	if (Current_State == 0)
	{
		LCD_enuClearDisplay();
		LCD_enuDisplayString("All Devices");
		LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
		LCD_enuDisplayString("Are Off");
	}
	else
		{
			while ( Local_u8Iterator <= 4)
			{	
				LCD_enuSendData('L');
				LCD_enuSendData('0'+Local_u8Iterator);
				LCD_enuSendData(':');
				On_Devices = ( GET_BIT( Current_State, Local_u8Iterator) )*Local_u8Iterator;	//We stored the state of each Device "On or Off" in a Corresponding bit in The Current_State Variable
				switch (On_Devices)
				{					
					case State_ROOM_1:
					LCD_enuSendData('+');			//"+" indicates On State and "-" indicates off State "We Choose this representation because the small size of the LCD in order to display the state of all device on the LCD on the Same time"
					break;
					case State_ROOM_2:
					LCD_enuSendData('+');
					break;
					case State_ROOM_3:
					LCD_enuSendData('+');
					break;
					case State_ROOM_4:
					LCD_enuSendData('+');
					break;
					default:
					LCD_enuSendData('-');
					break;
				}
			Local_u8Iterator ++;
			}
			LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
			LCD_enuDisplayString("Dim:");
			LCD_enuDisplayUnsignedInteger(Dimmer_Percentage);
			
			LCD_enuDisplayString(" A.Con:");
			if ((!GET_BIT( Current_State, 6)) && (!GET_BIT( Current_State, 5)) )		//For Air Conditioner, We have 3 Possibilities: Open, Close and Auto. So, We will represent these 3 possibilities by 2 bits
			{
				LCD_enuDisplayString("Auto");											//The 2 bits are zero in the Automatic Control State
			}
			else if ((!GET_BIT( Current_State, 6)) && (GET_BIT( Current_State, 5)))		//The sixth bit is zero and the fifth bit is one for "On" state
			{
				LCD_enuDisplayString("On");
			}
			else
			{
				LCD_enuDisplayString("Off");											//Otherwise "Off" State
			}
					
					
		/*	case State_Door:
		LCD_enuClearDisplay();
		LCD_enuDisplayString("Door is Opened");
		_delay_ms(1000);
		break;*/
		}
		while (Program_Status_Flag == IDLE_STATE)
					if(UART_enuCheck_Connection())
					{
						Program_Status_Flag = REMOTED_SYSTEM_LOGIN_PAGE_STATE;
					}			
	
		}//end of the IDLE_STATE
				
/************************************************************************************REMOTED_SYSTEM_LOGIN_PAGE_STATE********************************************************************************************/
/****************The Program Enters This State if A User is Connected to the remoted System through bluetooth and Started a Login Attempt by Pressing any Key into the Bluetooth Terminal**********************/
/*******************************************It takes the username and password from the user and Compare it with the admin info and the Remoted users database************************************************/
		while (Program_Status_Flag == REMOTED_SYSTEM_LOGIN_PAGE_STATE)
		{
			u8 LoginSystem_u8_AdminTrueFlag;
			u8 LoginSystem_u8_Remoted_USERTrueFlag;
			LoginSystem_enuGetDataFromUserBY_UART(LoginSystem_Au8Username, LoginSystem_Au8Password);
			
			LoginSystem_u8_AdminTrueFlag = (LoginSystem_u8Strcmp(LoginSystem_Au8Username,LoginSystem_strAdmin.UserName)) && ( LoginSystem_u8Strcmp(LoginSystem_Au8Password,LoginSystem_strAdmin.Password) ) ; //Comparing The Acquired Password and Username with The admin info 

			if(LoginSystem_u8_AdminTrueFlag == TRUE)
			{
				UART_enuSendString("\r\nLogged in Successfully");
				_delay_ms(500);
				UART_enuSendString("\r\nWelcome Admin\r\n");
				_delay_ms(500);
				LoginSystem_u8AdminOnlineFlag = TRUE;
				LoginSystem_u8TrialsLeft =3;
				Program_Status_Flag = REMOTED_SYSTEM_MENU_STATE;	
			}
			else
			{
				for (u8 Local_u8Iterator=0; Local_u8Iterator < LoginSystem_NumOfRegisteredUsers; Local_u8Iterator++) //Searching the remoted users data bases for a match for the Acquired Username and Password
				{
								
					LoginSystem_u8_Remoted_USERTrueFlag = LoginSystem_u8Strcmp (LoginSystem_AstrUsers[Local_u8Iterator].UserName,LoginSystem_Au8Username) && LoginSystem_u8Strcmp (LoginSystem_AstrUsers[Local_u8Iterator].Password,LoginSystem_Au8Password);
					if ( (LoginSystem_u8_Remoted_USERTrueFlag == TRUE)  )
					{
						if ( (LoginSystem_AstrUsers[Local_u8Iterator].User_Priority == REMOTED_USER) || (LoginSystem_AstrUsers[Local_u8Iterator].User_Priority == PROMOTED_USER) )
						{
							UART_enuSendString("\r\nLogged in Successfully\r\n");
							_delay_ms(500);
							LoginSystem_u8TrialsLeft =3;
							Program_Status_Flag = REMOTED_SYSTEM_MENU_STATE;
							if (LoginSystem_AstrUsers[Local_u8Iterator].User_Priority == PROMOTED_USER)
							{
								LoginSystem_u8PromotedUserOnlineFlag = TRUE;
							}
							break;
						}
						else
						{	
							LoginSystem_u8_Remoted_USERTrueFlag = FALSE;
							break;
						}
					}
					
						
				}
			}
			
			if ( (LoginSystem_u8_AdminTrueFlag == FALSE)&& (LoginSystem_u8_Remoted_USERTrueFlag ==FALSE) )
			{
				LoginSystem_u8TrialsLeft--;
				UART_enuSendString("\r\nWrong Username or Password");
				_delay_ms(300);
				UART_enuSendString("\r\nRemaining Trials: ");
				UART_enuSendChar('0'+LoginSystem_u8TrialsLeft);
							//_delay_ms(1000);
				if (LoginSystem_u8TrialsLeft == 0)
				{
					Program_Status_Flag = BLOCKING_STATE;
				}
			}
					
		}//end of the REMOTED_SYSTEM_LOGIN_PAGE_STATE
				
/**********************************************************************************************REMOTED_SYSTEM_MENU_STATE********************************************************************************************/
/****************The Program Enters This State The User Entered Matched Username and Password With The Admin info or the Remoted users database in the Remoted System Login Page "The Previous State"**************/
/************************************************It Displays The Menu of the Smart Home to The Remoted User and Displays Aditional Options To The Admin Only******************************************************/
		while (Program_Status_Flag == REMOTED_SYSTEM_MENU_STATE)
		{
			
			while(ShowToUser == MAIN_MENU && Program_Status_Flag == REMOTED_SYSTEM_MENU_STATE)  //"Program_Status_Flag == REMOTED_SYSTEM_MENU_STATE" This condition is added here because if there's a remoted user entered this while loop and meanwhile a LCD_keypad Raised an interrupt by pressing the button "EXTI" to start a login attempt this action will result in logging the remoted user out as the LCD_Keypad user have More Priority "Except For Promoted Users and Admin" 
			{
			//The first six chioces will Appear for Admin or Remoted user 
			UART_enuSendString("\r\n1-Room1");
			UART_enuSendString("\r\n2-Room2");
			UART_enuSendString("\r\n3-Room3");
			UART_enuSendString("\r\n4-Room4");
			UART_enuSendString("\r\n5-Dimmer");
			UART_enuSendString("\r\n6-Air Conditioner");

			if (LoginSystem_u8AdminOnlineFlag ==TRUE) //The Last 3 options will Appear only to Admin
			{
				UART_enuSendString("\r\n7-Door");
				UART_enuSendString("\r\n8-Add User");
				UART_enuSendString("\r\n9-Remove User\r\n");

				UART_enuRecieveChar(&UART_CHOICE);
			}
				else
				{
					UART_enuSendString("\r\n");		//For the shape of menu
					UART_enuRecieveChar(&UART_CHOICE);
					if (UART_CHOICE > '6')
						UART_CHOICE =100;		//If the program enter this else, then a Remoted User is in control. So, We want him to go to default in the switch case if he entered by mistake a number that corresponds An admin option in the switch case
				}
				
				switch(UART_CHOICE)
				{
					case '1':
						SPI_ui8TransmitRecive(ROOM1_LED_TOGGLE);
						ToggleBit(&Current_State,1);
						ShowToUser = LOG_OUT_CHOICE;
					break;
					
					case '2':
						SPI_ui8TransmitRecive(ROOM2_LED_TOGGLE);
						ToggleBit(&Current_State,2);
						ShowToUser = LOG_OUT_CHOICE;
					break;
					
					case '3':
						SPI_ui8TransmitRecive(ROOM3_LED_TOGGLE);
						ToggleBit(&Current_State,3);
						ShowToUser = LOG_OUT_CHOICE;
					break;
					
					case '4':
						SPI_ui8TransmitRecive(ROOM4_LED_TOGGLE);
						ToggleBit(&Current_State,4);
						ShowToUser = LOG_OUT_CHOICE;
					break;
					
					case '5':
						SPI_ui8TransmitRecive(DIMMER);
						ShowToUser = DIMMER_MENU;
					break;
					
					case '6':
						ShowToUser = AIR_COND_MENU;  
					break;
					case '7':
					ShowToUser = DOOR_MENU;
					break;
					
					
					case '8':
						if (LoginSystem_NumOfRegisteredUsers <MAX_NO_OF_USERS)
							{
								LoginSystem_enuGetDataFromUserBY_UART(LoginSystem_AstrUsers[LoginSystem_NumOfRegisteredUsers].UserName, LoginSystem_AstrUsers[LoginSystem_NumOfRegisteredUsers].Password);
								ShowToUser = PRIORITIES_MENU;
							}
						else
							{
								UART_enuSendString("\r\nReached The Max Number of Stored Users");
								UART_enuSendString("\r\nCouldn't Store A New User");
								UART_enuSendString("\r\nReturning to Main Menu\r\n");
								ShowToUser = MAIN_MENU;
								_delay_ms(700);
							}
					break;
					case '9':
						if (LoginSystem_RemoveUser(LoginSystem_AstrUsers,&LoginSystem_NumOfRegisteredUsers) == TRUE)
						{		UART_enuSendString("\r\nRemoved Successfully\r\n");
								ShowToUser=LOG_OUT_CHOICE;
						}
						else	{UART_enuSendString("\r\nUsername not Found \r\nReturning to Main Menu\r\n");}
						ShowToUser=MAIN_MENU;
						_delay_ms(700);
					break;

					default:
					UART_enuSendString("\r\nInvalid Choice\r\n");
					_delay_ms(1000);
					ShowToUser = MAIN_MENU;
					break;
				}
			}
			switch (ShowToUser)
			{
				case PRIORITIES_MENU:
						UART_enuSendString("\r\n1-Remoted");
						UART_enuSendString("\r\n2-Promoted");
						UART_enuSendString("\r\n3-Nonremoted");
						UART_enuSendString("\r\n\r\nPriority Arrangment: Promoted > Nonremoted (LCD+Keypad) > Remoted\r\n");
						UART_enuRecieveChar(&UART_CHOICE);
						if (UART_CHOICE == '1')
							{LoginSystem_AstrUsers [LoginSystem_NumOfRegisteredUsers].User_Priority = REMOTED_USER;
							LoginSystem_SaveNewUser(LoginSystem_AstrUsers [LoginSystem_NumOfRegisteredUsers],&LoginSystem_NumOfRegisteredUsers);
							ShowToUser = LOG_OUT_CHOICE;
							UART_enuSendString("\r\nRegistered Successfully\r\n");}
						else if (UART_CHOICE == '2')
							{LoginSystem_AstrUsers [LoginSystem_NumOfRegisteredUsers].User_Priority = PROMOTED_USER;
							LoginSystem_SaveNewUser(LoginSystem_AstrUsers [LoginSystem_NumOfRegisteredUsers],&LoginSystem_NumOfRegisteredUsers);
							ShowToUser = LOG_OUT_CHOICE;
							UART_enuSendString("\r\nRegistered Successfully\r\n");}
						else if (UART_CHOICE == '3')
							{LoginSystem_AstrUsers [LoginSystem_NumOfRegisteredUsers].User_Priority = LCD_KEYPAD_USER;
							LoginSystem_SaveNewUser(LoginSystem_AstrUsers [LoginSystem_NumOfRegisteredUsers],&LoginSystem_NumOfRegisteredUsers);
							ShowToUser = LOG_OUT_CHOICE;
							UART_enuSendString("\r\nRegistered Successfully\r\n");}
						else
						{
							UART_enuSendString("\r\nInvalid Choice\r\n");
							_delay_ms(1000);	
						}
						
				break;
				
				case DIMMER_MENU:
					UART_enuSendString("\r\nEnter The Percentage of Brightness: ");
					UART_enuRecieveChar(&Dimmer_Percentage_Tens);
					UART_enuSendChar(Dimmer_Percentage_Tens);
					Dimmer_Percentage_Tens = Dimmer_Percentage_Tens - '0';
					
					UART_enuRecieveChar(&Dimmer_Percentage_Ones);
					UART_enuSendChar(Dimmer_Percentage_Ones);
					Dimmer_Percentage_Ones = Dimmer_Percentage_Ones -'0';
					
					Dimmer_Percentage =10*Dimmer_Percentage_Tens + Dimmer_Percentage_Ones;
					
					SPI_ui8TransmitRecive(Dimmer_Percentage);
					ShowToUser=LOG_OUT_CHOICE;
				break;
				
				case DOOR_MENU:
					UART_enuSendString("\r\nDoor Options \r\n 1-Open Door\r\n 2-Close Door\r\n 0-Return to main menu\r\n ");
					UART_enuRecieveChar(&UART_CHOICE);
					if (UART_CHOICE == '1')
					{
						SPI_ui8TransmitRecive(OPEN_DOOR_COMMAND);	
						ShowToUser = LOG_OUT_CHOICE;
					}
					else if(UART_CHOICE == '2')
					{
						SPI_ui8TransmitRecive(CLOSE_DOOR_COMMAND);
						ShowToUser = LOG_OUT_CHOICE;
					}
					else if (UART_CHOICE == '0') 
						{ShowToUser = MAIN_MENU;} 
					else{UART_enuSendString("\r\nInvalid Choice\r\n ");		ShowToUser = DOOR_MENU;}
				break;
				case AIR_COND_MENU:
					
					UART_enuSendString("\r\n1-Open\r\n2-Close\r\n3-Automatic Control");
					UART_enuRecieveChar(&UART_CHOICE);
					if(UART_CHOICE == '1')
					{
						SPI_ui8TransmitRecive(OPEN_AirCond_COMMAND);
						ClearBit(&Current_State,6);
						SetBit(&Current_State,5);
					}	
					else if(UART_CHOICE == '2')
					{
						SPI_ui8TransmitRecive(CLOSE_AirCond_COMMAND);
						SetBit(&Current_State,6);
						SetBit(&Current_State,5);
					}
					else if(UART_CHOICE == '3')
					{
						SPI_ui8TransmitRecive(AUTO_AirCond_COMMAND);
						ClearBit(&Current_State,6);
						ClearBit(&Current_State,5);
					}
					ShowToUser = LOG_OUT_CHOICE;
				break;
				
				case LOG_OUT_CHOICE:
					UART_enuSendString("\r\n\r\n1-Log Out\r\n2-Return to main menu\r\n");
					UART_enuRecieveChar(&UART_CHOICE);
					if (UART_CHOICE == '1')
						{
							Program_Status_Flag = IDLE_STATE;	
							ShowToUser = MAIN_MENU;			//That's For the next time The Program Enters the ADMIN Menu State to Start From the MAIN Menu 
							UART_enuSendString("\r\nLogged Out\r\n");
							if (LoginSystem_u8AdminOnlineFlag == TRUE)	//If an Admin was online and wants to log out
								LoginSystem_u8AdminOnlineFlag = FALSE;	
							else if (LoginSystem_u8PromotedUserOnlineFlag == TRUE)	//If a promoted user was online and wants to log out
								LoginSystem_u8PromotedUserOnlineFlag = FALSE;
						}
				
					else if(UART_CHOICE == '2')
						{ShowToUser = MAIN_MENU;}
					else{UART_enuSendString("\r\nInvalid Choice\r\n ");		ShowToUser = LOG_OUT_CHOICE;}
				break;
				
			}
		}//end of the REMOTED_SYSTEM_MENU_STATE
		
/***********************************************************************************************LCD_KEYPAD_LOGIN_PAGE_STATE*********************************************************************************************************/
/****************The Program Enters This State if A User Started a Login Attempt To LCD_Keypad System By Pressing A Button That generates an EXT interrupt The Transfers the Program_Status_Flag into this state*******************/
/***********************************************************It takes the username and password from the user and Compare it with NonRemoted users database************************************************************************/
		while (Program_Status_Flag == LCD_KEYPAD_LOGIN_PAGE_STATE)//off-line user should have Button interrupt
		{	
				LCD_enuClearDisplay();
				LCD_enuDisplayString("User Login");
				LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
				LCD_enuDisplayString("Attempt Detected");
				_delay_ms(700);
				u8 LoginSystem_u8TrueFlag;
				LoginSystem_enuGetDataFromUserByKeypad(LoginSystem_Au8Username, LoginSystem_Au8Password);
				/*********************Search The Users Array***********************/
				for (u8 Local_u8Iterator=0; Local_u8Iterator < LoginSystem_NumOfRegisteredUsers; Local_u8Iterator++) //Searching the Nonremoted users data bases for a match for the Acquired Username and Password
				{
					LoginSystem_u8TrueFlag = LoginSystem_u8Strcmp (LoginSystem_AstrUsers[Local_u8Iterator].UserName,LoginSystem_Au8Username) && LoginSystem_u8Strcmp (LoginSystem_AstrUsers[Local_u8Iterator].Password,LoginSystem_Au8Password);
					if ( LoginSystem_u8TrueFlag == TRUE  )
					{	
						if ( (LoginSystem_AstrUsers[Local_u8Iterator].User_Priority == LCD_KEYPAD_USER) )
						{
							LoginSystem_u8TrialsLeft =3;
							LCD_enuClearDisplay();
							LCD_enuDisplayString("Logged in");
							LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
							LCD_enuDisplayString("Successfully");
							_delay_ms(700);
							LCD_enuClearDisplay();
							LCD_enuDisplayString("Welcome User");
							_delay_ms(700);
							Program_Status_Flag = LCD_KEYPAD_MENU_STATE;
							break;
						}
						else
						{
							LoginSystem_u8TrueFlag = FALSE;
							break;
						}
					}
					
				}
				if (LoginSystem_u8TrueFlag == FALSE)
				{
					LoginSystem_u8TrialsLeft--;
					LCD_enuClearDisplay();
					LCD_enuDisplayString("Wrong Username");
					LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
					LCD_enuDisplayString("or Password");
					_delay_ms(700);
					LCD_enuClearDisplay();
					LCD_enuDisplayString("Remaining Trials: ");
					LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
					LCD_enuDisplayUnsignedInteger(LoginSystem_u8TrialsLeft);
					_delay_ms(700);
					if (LoginSystem_u8TrialsLeft == 0)
					{
						Program_Status_Flag = BLOCKING_STATE;
					}
				}

		}//end of the LCD_KEYPAD_LOGIN_PAGE_STATE
		
/*************************************************************************************LCD_KEYPAD_MENU_STATE*************************************************************************************/
/****************The Program Enters This State if The User Entered Matched Username and Password With Nonremoted users database in the LCD Keypad Login Page "The Previous State"**************/
/***************************************************************It Displays The Menu of the Smart Home to The Nonremoted User*****************************************************************/
		while (Program_Status_Flag == LCD_KEYPAD_MENU_STATE)//off line user menu
		{
			while(ShowToUser == MAIN_MENU)
			{
				LCD_enuClearDisplay();			
				LCD_enuDisplayString("1:Room1 2:Room2");
				LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
				LCD_enuDisplayString("3:Room3 4:More");
				Keypad_enuGetPressedKey(&Keypad_Pressed_Key);
				switch (Keypad_Pressed_Key)
				{
				case '1':
					SPI_ui8TransmitRecive(ROOM1_LED_TOGGLE);
					ToggleBit(&Current_State,1);
					ShowToUser = LOG_OUT_CHOICE;
				break;
				
				case '2':
					SPI_ui8TransmitRecive(ROOM2_LED_TOGGLE);
					ToggleBit(&Current_State,2);
					ShowToUser = LOG_OUT_CHOICE;
				break;
				
				case '3':
					SPI_ui8TransmitRecive(ROOM3_LED_TOGGLE);
					ToggleBit(&Current_State,3);
					ShowToUser = LOG_OUT_CHOICE;
				break;
				
				case '4':
					ShowToUser = MORE_MENU;
				break;
				
				default:
				LCD_enuClearDisplay();
				LCD_enuDisplayString("Invalid Choice");
				_delay_ms(700);
				break;
				}
			}
			
			while (ShowToUser == MORE_MENU)
			{
					
				LCD_enuClearDisplay();
				LCD_enuDisplayString("1:Room4 2:Dimmer");
				LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
				LCD_enuDisplayString("3:AirCond 0:Ret");
				Keypad_enuGetPressedKey(&Keypad_Pressed_Key);
				switch (Keypad_Pressed_Key)
				{
					case '1':
					SPI_ui8TransmitRecive(ROOM4_LED_TOGGLE);
					ToggleBit(&Current_State,4);
					ShowToUser = LOG_OUT_CHOICE;
					break;
					
					case '2':
					SPI_ui8TransmitRecive(DIMMER);
					
					ShowToUser = DIMMER_MENU;
					break;
					
					case '3':
					LCD_enuClearDisplay();
					LCD_enuDisplayString("1-Open 2-Close");
					LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
					LCD_enuDisplayString("3-Automatic");
					Keypad_enuGetPressedKey(&Keypad_Pressed_Key);
					if(Keypad_Pressed_Key == '1')
					{
						SPI_ui8TransmitRecive(OPEN_AirCond_COMMAND);
						ClearBit(&Current_State,6);
						SetBit(&Current_State,5);
					}
					else if(Keypad_Pressed_Key == '2')
					{
						SPI_ui8TransmitRecive(CLOSE_AirCond_COMMAND);
						SetBit(&Current_State,5);
						SetBit(&Current_State,6);
					}
					else if(Keypad_Pressed_Key == '3')
					{
						SPI_ui8TransmitRecive(AUTO_AirCond_COMMAND);
						ClearBit(&Current_State,6);
						ClearBit(&Current_State,5);
					}
					ShowToUser = LOG_OUT_CHOICE;
					break;
					case '0':
					ShowToUser = MAIN_MENU;
					break;
					
					default:
					LCD_enuClearDisplay();
					LCD_enuDisplayString("Invalid Choice");
					_delay_ms(700);
					break;
				}
			}
			switch(ShowToUser)
			{
				case DIMMER_MENU:
					LCD_enuClearDisplay();
					LCD_enuDisplayString("Brightness");
					LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
					LCD_enuDisplayString("Percentage:");
					Keypad_enuGetPressedKey(&Dimmer_Percentage_Tens);
					LCD_enuSendData(Dimmer_Percentage_Tens);
					Dimmer_Percentage_Tens = Dimmer_Percentage_Tens - '0';
					Keypad_enuGetPressedKey(&Dimmer_Percentage_Ones);
					LCD_enuSendData(Dimmer_Percentage_Ones);
					Dimmer_Percentage_Ones = Dimmer_Percentage_Ones -'0';
					Dimmer_Percentage =10*Dimmer_Percentage_Tens + Dimmer_Percentage_Ones;
					SPI_ui8TransmitRecive(Dimmer_Percentage);
					_delay_ms(700);
					ShowToUser=LOG_OUT_CHOICE;
				break;
				
				case LOG_OUT_CHOICE:
					LCD_enuClearDisplay();
					LCD_enuDisplayString("1:Log Out 2:Ret");
					Keypad_enuGetPressedKey(&Keypad_Pressed_Key);
					if (Keypad_Pressed_Key == '1')
					{
						Program_Status_Flag = IDLE_STATE;
						ShowToUser = MAIN_MENU;			//That's For the next time The Program Enters the ADMIN Menu State to Start From the MAIN Menu
						LCD_enuClearDisplay();
						LCD_enuDisplayString("Logged Out");
						
						_delay_ms(700);
					}
					else if(Keypad_Pressed_Key == '2')
						{ShowToUser = MAIN_MENU;}
					else{LCD_enuClearDisplay();		LCD_enuDisplayString("Invalid Choice");	 _delay_ms(700);	ShowToUser = LOG_OUT_CHOICE;}
				break;
			}
		}//end of the LCD_KEYPAD_MENU_STATE


		if(Program_Status_Flag == BLOCKING_STATE)
		{
			EEPROM_vWriteByteToAddress(SAVED_INITIAL_PROGRAM_STATE_ADDRESS,BLOCKING_STATE);
			Blocking_Flag=TRUE;
			LCD_enuClearDisplay();
			LCD_enuDisplayString("You are Blocked");
			LCD_enuSetCursorPosition(LCD_u8YDIM_1,LCD_u8XDIM_0);
			LCD_enuDisplayString("From The System");
			DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN0,DIO_u8HIGH);
			while (Program_Status_Flag == BLOCKING_STATE);
			
		}//end of the Blocking STATE
		

	}//end of the while (1)



	return 0;
}//end of main()

volatile void Button_Pressed_Interrupt()  //The function that's executed on the EXT INT ISR interrupt When a button is pressed Which Indicates that a LCD_KEYPAD user wants to initiate a login attempt,So it switch the program state into the "LCD_KEYPAD_LOGIN_PAGE_STATE"
{
	if (!(LoginSystem_u8AdminOnlineFlag || LoginSystem_u8PromotedUserOnlineFlag || Blocking_Flag ))
	{
		Program_Status_Flag = LCD_KEYPAD_LOGIN_PAGE_STATE;
		ShowToUser = MAIN_MENU;
	}
	
}

