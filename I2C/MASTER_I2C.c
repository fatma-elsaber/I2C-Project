////////code of master/////////
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TWI_int.h"
#include "TWI_Config.h"
#include "GIE_Interface.h"
#include "TMR0_Interface.h"

void LED_TOGGLE()
{
    static u16 counter = 0;
        counter++;

        if (counter >= 1000)
        {
            DIO_voidToggelPin(PORTA_ID, PIN_0);
            counter = 0;
            TIMER0_VoidSetPreload(192);
        }

}
int main(void)
{
	DIO_voidSetPinDirection(PORTA_ID,PIN_0,PIN_OUTPUT);
	M_TWI_void_Init();

	TIMER0_VoidInit();
	TIMER_voidSetCallBack(LED_TOGGLE);
	TIMER0_VoidSetPreload(192);
	GIE_Enable();
	TIMER0_VoidStop();

	while(1)
	{
		M_TWI_u8_StartCondition();
		M_TWI_u8_SendSlaveAddressWrite(SLAVE_ADDRESS);
		M_TWI_u8_SendByte('2');
		 M_TWI_u8_RepeatedStart();
		 M_TWI_u8_SendSlaveAddressRead(SLAVE_ADDRESS);
		M_TWI_void_StopCondition();
		TIMER0_VoidStart();

	}
}

