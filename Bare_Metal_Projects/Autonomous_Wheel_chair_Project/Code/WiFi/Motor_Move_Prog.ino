#include "Motor_Move_Init.h"

/****** Motors Moves Functions Definitions ******/
/**
 * @brief : Motor Move Forward
 * @Param : Void
 */
void Motor_Forward(void) 
{
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
}

/**
 * @brief : Motor Move Reverse
 * @Param : Void
 */
void Motor_Reverse(void) 
{
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}

/**
 * @brief : Motor Move Right
 * @Param : Void
 */
void Motor_Right(void) 
{
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}

/**
 * @brief : Motor Move Left
 * @Param : Void
 */
void Motor_Left(void) 
{
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
}

/**
 * @brief : Motor Stop
 * @Param : Void
 */
void Motor_Stop(void)
{
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
}