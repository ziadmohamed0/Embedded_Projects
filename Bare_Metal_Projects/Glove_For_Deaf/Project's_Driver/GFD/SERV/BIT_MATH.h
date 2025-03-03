/************************************************************************
 *                                                                      *
 *************************  Date    : 17/2/2024       *******************
 *************************  Name    : Ziad Mohammed   *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : BIT MATH        *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef BIT_MATH_H_ 
#define BIT_MATH_H_
 
#define SET_BIT(REG,BIT_NUM)    REG|=(1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)    REG&=(~(1<<BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)    REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)    ((REG>>BIT_NUM)&1)
 
#endif