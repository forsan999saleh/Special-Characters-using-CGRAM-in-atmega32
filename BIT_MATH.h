

#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(Var,BitNo)    Var |=  (1 << (BitNo))
#define CLR_BIT(Var,BitNo)    Var &= ~(1 << (BitNo))
#define GET_BIT(Var,BitNo)    Var &   (1 << (BitNo))
#define TOG_BIT(Var, BitNo)   Var ^   (1 << (BitNo))



#endif
