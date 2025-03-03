

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,n) (x |=(1<<n))
#define GET_BIT(x,n) ((x >> n) & 0b00000001)
#define CLR_BIT(x,n) (x &=~(1<<n))
#define TOG_BIT(x,n) (x ^=(1<<n))

#endif /* BIT_MATH_H_ */
