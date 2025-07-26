################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../GIE_Program.c \
../LCD_programm.c \
../MASTER_I2C.c \
../TMR0_Program.c \
../TWI_prog.c 

OBJS += \
./DIO_program.o \
./GIE_Program.o \
./LCD_programm.o \
./MASTER_I2C.o \
./TMR0_Program.o \
./TWI_prog.o 

C_DEPS += \
./DIO_program.d \
./GIE_Program.d \
./LCD_programm.d \
./MASTER_I2C.d \
./TMR0_Program.d \
./TWI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


