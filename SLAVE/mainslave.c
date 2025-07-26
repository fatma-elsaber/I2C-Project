////////////code of slave////////////////
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TWI_int.h"
#include "LCD_interface.h"


int main(void)
{
	u8 data;
	M_TWI_void_Init();
	DIO_voidSetPinDirection(PORTA_ID,PIN_0,PIN_OUTPUT);

	LCD_voidInit();

	LCD_voidWriteString((u8 *) "  Welcome...");
	_delay_ms(2000);
	LCD_voidClear();


	while(1)
	{
		M_TWI_u8_ReadByte(&data);
		if(data=='2')
		{
			DIO_voidSetPinValue(PORTA_ID,PIN_0,PIN_HIGH);
			LCD_voidWriteString((u8 *)" LED IS ON");
			_delay_ms(500);

		}
		else if (data=='1')
		{
			DIO_voidSetPinValue(PORTA_ID,PIN_0,PIN_LOW);
			LCD_voidWriteString((u8 *)" LED IS OFF");
			_delay_ms(500);

		}

	}
}

