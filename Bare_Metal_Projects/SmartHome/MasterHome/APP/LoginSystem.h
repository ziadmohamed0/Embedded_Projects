#ifndef APP_LOGINSYSTEM_H_
#define APP_LOGINSYSTEM_H_



ES_t LoginSystem_enuGetDataFromUserByKeypad(u8 *Copy_Au8Username, u8 *Copy_Au8Password);
ES_t LoginSystem_enuGetDataFromUserBY_UART(u8 *Copy_Au8Username, u8 *Copy_Au8Password);
ES_t LoginSystem_SaveNewUser(User_t Copy_strNewUser,u8 *Copy_u8NumofRegisteredUsers);
u8 LoginSystem_RemoveUser(User_t *Copy_AstrUsers,u8 *Copy_u8NumofRegisteredUsers);
u8 LoginSystem_u8Strcmp (char *Copy_Au8Sring1, char *Copy_Au8Sring2);
void SetBit(u8 *x,u8 n);
void ToggleBit(u8 *x,u8 n);
#endif /* APP_LOGINSYSTEM_H_ */
