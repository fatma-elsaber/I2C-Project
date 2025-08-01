/*
 * LCD_interface.h
 *
 *  Created on: 20 Jul 2025
 *      Author: elsab
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);

void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);



void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);

void LCD_voidWriteNumber( u32 Copy_u8num );


void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum );

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum ) ;


#endif /* LCD_INTERFACE_H_ */
