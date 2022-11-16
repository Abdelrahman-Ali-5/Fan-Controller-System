 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Abdelrahman Ali Mohamed
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* Get the value of a certain bit in any register and return true if the bit is LOGIC HIGH */
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

/* Write a value ( LOGIC_HIGH or LOGIC_LOW ) into a certain pin in certain register */
#define WRITE_BIT(REG,BIT_NUM,VALUE){\
switch (VALUE){\
	case LOGIC_LOW : CLEAR_BIT(REG,BIT_NUM);\
	break;\
	case LOGIC_HIGH : SET_BIT(REG,BIT_NUM);\
	break;\
}\
}

/* Setup the direction of a certain bit in a register to be INPUT or OUTPUT */
#define SETUP_PIN_DIRECTION(REG,BIT_NUM,VALUE) {\
switch (VALUE){\
	case PIN_OUTPUT : SET_BIT(REG,BIT_NUM);\
	break;\
	case PIN_INPUT : CLEAR_BIT(REG,BIT_NUM);\
}\
}


#endif
