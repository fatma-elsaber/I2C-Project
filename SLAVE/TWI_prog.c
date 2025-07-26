/*
 * TWI_program.c
 *
 *  Created on: 25 Jul 2025
 *      Author: elsab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "TWI_int.h"
#include "TWI_Config.h"
#include "TWI_private.h"
#include "LCD_Interface.h"


/*------------------------------------------------------------------------*/

void M_TWI_void_Init(void)
{
#if   TWI_MODE   ==   TWI_MASTER_MODE
	TWBR_REG = (  ( ((u32)F_OSC * 1000000) / F_SCL) - 16) / 2;
	CLR_BIT(TWSR_REG,TWSR_TWPS0);
	CLR_BIT(TWSR_REG,TWSR_TWPS1);

	//TWAR_REG = (SLAVE_ADDRESS << 1) | GENERAL_CALL;

#elif TWI_MODE   ==   TWI_SLAVE_MODE
	/* set SLAVE_ADDRESS and if GENERAL_CALL on  */
	TWAR_REG = (SLAVE_ADDRESS << 1) | GENERAL_CALL;

#endif


	/*EN ACK*/
	SET_BIT(TWCR_REG,TWCR_TWEA);

	/*EN TWI */
	SET_BIT(TWCR_REG,TWCR_TWEN);
}


/*------------------------------------------------------------------------*/



TWI_ERROR_STATUS M_TWI_u8_StartCondition(void)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;


	/* Start Condition */

	SET_BIT(TWCR_REG,TWCR_TWSTA);

	/* to clear the flag */
	SET_BIT(TWCR_REG,TWCR_TWINT);


	while(GET_BIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_START_COND_ACK)
	{
		local_error=START_ERROR;
	}
	else
	{

	}


	return  local_error ;
}

/***************************************************************************/

void M_TWI_void_StopCondition(void)

{

	/* Stop Condition */
	SET_BIT(TWCR_REG,TWCR_TWSTO);

	/* to clear the flag */
	SET_BIT(TWCR_REG,TWCR_TWINT);

}

/***************************************************************************/

TWI_ERROR_STATUS M_TWI_u8_RepeatedStart(void)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;


	/* Start Condition */
	SET_BIT(TWCR_REG,TWCR_TWSTA);


	/* to clear the flag */
	SET_BIT(TWCR_REG,TWCR_TWINT);


	while(GET_BIT(TWCR_REG,TWCR_TWINT) == 0);


	if((TWSR_REG & 0xF8) != TWI_REPEATED_START_COND_ACK)
	{
		local_error=REPEATED_STSRT_ERROR;
	}
	else
	{

	}


	return  local_error ;
}

/***************************************************************************/



TWI_ERROR_STATUS M_TWI_u8_SendSlaveAddressWrite(u8 Copy_u8Address)
{

	TWI_ERROR_STATUS local_error = NO_ERROR ;


	TWDR_REG = (Copy_u8Address << 1);
	CLR_BIT(TWDR_REG,0);



	/* Clear Start condition */
	CLR_BIT(TWCR_REG,TWCR_TWSTA);

	/* to clear the flag */
	SET_BIT(TWCR_REG,TWCR_TWINT);

	while(GET_BIT(TWCR_REG,TWCR_TWINT) == 0);


	if((TWSR_REG & 0xF8) != TWI_SEND_SLAVE_ADD_WRITE_ACK)
	{
		local_error=SLAVE_ADDRESS_WRITE_ERROR;
	}
	else
	{

	}
	return  local_error ;
}

/***************************************************************************/

TWI_ERROR_STATUS M_TWI_u8_SendSlaveAddressRead(u8 Copy_u8Address)
{

	TWI_ERROR_STATUS local_error =NO_ERROR ;


	TWDR_REG = ( (Copy_u8Address << 1) | 1);

	/* Clear Start condition */
	CLR_BIT(TWCR_REG,TWCR_TWSTA);


	SET_BIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */


	while(GET_BIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_SEND_SLAVE_ADD_READ_ACK)
	{
		local_error=SLAVE_ADDRESS_READ_ERROR;
	}
	else
	{

	}
	return  local_error ;

}




/***************************************************************************/
TWI_ERROR_STATUS M_TWI_u8_SendByte(u8 Copy_u8Data)
{
	TWI_ERROR_STATUS local_error =NO_ERROR ;

	TWDR_REG = Copy_u8Data;
	/* Clear Start condition */
	//CLR_BIT(TWCR_REG,TWCR_TWSTA);


	SET_BIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */

	while(GET_BIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_SEND_BYTE_ACK)
	{
		local_error=SEND_BYTE_ERROR;
	}
	else
	{

	}
	return  local_error ;

}

/***************************************************************************/

TWI_ERROR_STATUS  M_TWI_u8_ReadByte(u8 *TWI_DATA)
{

	TWI_ERROR_STATUS local_error =NO_ERROR ;

	SET_BIT(TWCR_REG, TWCR_TWEA);

	SET_BIT(TWCR_REG,TWCR_TWINT);   /* to clear the flag */

	while(GET_BIT(TWCR_REG,TWCR_TWINT) == 0);

	if((TWSR_REG & 0xF8) != TWI_READ_BYTE_ACK)
	{
		local_error=READ_BYTE_ERROR;
	}
	else
	{
		*TWI_DATA = TWDR_REG;
	}


	*TWI_DATA = TWDR_REG;

	return  local_error ;
}

