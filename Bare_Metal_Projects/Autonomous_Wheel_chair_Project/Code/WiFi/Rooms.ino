#include "Rooms_Init.h"

/****** Rooms Functions Definitions ******/
/**
 * @brief : Chair Move To home From Any Room.
 * @Param : Void
 */
void Home(void)
{
    if(Flage_Rooms == 1)
  {
    Motor_Forward();
    delay(900);
    Motor_Stop();
    delay(800);

    Motor_Right();
    delay(600);
    Motor_Stop();
    delay(800);

    Motor_Forward();
    delay(885);
    Motor_Stop();

    Flage_Rooms = 0 ;
  }

  if(Flage_Rooms == 2)
  {
    
    Motor_Forward();
    delay(800);
    Motor_Stop();

    Motor_Left();
    delay(500);
    Motor_Stop();
    delay(800);

    Motor_Forward();
    delay(400);
    Motor_Stop();
    delay(800);  

    Motor_Left();
    delay(500);
    Motor_Stop();
    delay(800);

    Motor_Forward();
    delay(2400);
    Motor_Stop();

    Flage_Rooms = 0 ;
  }

  if(Flage_Rooms == 3)
  {

    Motor_Forward();
    delay(400);
    Motor_Stop();
    delay(800);

    Motor_Right();
    delay(500);
    Motor_Stop();
    delay(800);

    Motor_Forward();
    delay(400);
    Motor_Stop();
    delay(800);

    Motor_Left();
    delay(500);
    Motor_Stop();
    delay(800);

    Motor_Forward();
    delay(2400);
    Motor_Stop();

    Flage_Rooms = 0 ;
  }
  
}

/**
 * @brief : Chair Move To X_ray From Zero point.
 * @Param : Void
 */
void X_ray(void) 
{
  Motor_Forward();
  delay(2400);
  Motor_Stop();
  delay(800);

  Motor_Left();
  delay(500);
  Motor_Stop();
  delay(800);

  Motor_Forward();
  delay(400);
  Motor_Stop();
  delay(800);

  Motor_Right();
  delay(500);
  Motor_Stop();
  delay(800);

  Motor_Forward();
  delay(800);
  Motor_Stop();

  Flage_Rooms = 2 ;
}

/**
 * @brief : Chair Move To pharmacy From Zero point.
 * @Param : Void
 */
void pharmacy(void) 
{
  Motor_Forward();
  delay(885);
  Motor_Stop();
  delay(800);

  Motor_Right();
  delay(600);
  Motor_Stop();
  delay(800);

  Motor_Forward();
  delay(900);
  Motor_Stop();

  Flage_Rooms = 1 ;
}

/**
 * @brief : Chair Move To laboratory From Zero point.
 * @Param : Void
 */
void laboratory(void) 
{
  Motor_Forward();
  delay(2400);
  Motor_Stop();
  delay(800);

  Motor_Left();
  delay(500);
  Motor_Stop();
  delay(800);

  Motor_Forward();
  delay(400);
  Motor_Stop();
  delay(800);

  Motor_Right();
  delay(500);

  Motor_Stop();
  delay(800);

  Motor_Forward();
  delay(800);
  Motor_Stop();
  Flage_Rooms = 3 ;
}