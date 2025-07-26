# 🔌 I2C LED Control using ATmega32

A simple project that demonstrates I2C communication between two ATmega32 microcontrollers.  
The master sends a number to the slave via I2C, and if the number is 2, the slave turns on an LED.

---

## 🎯 Features

- I2C communication setup between Master and Slave
- Conditional control: turn LED ON when data = 2
- Conditional control: turn LED OFF when data = 1
- Uses AVR C with custom I2C driver

---

## 💻 Files Included

- TWI_program.c – I2C communication functions
- main_master.c – Code for the master device
- main_slave.c – Code for the slave device
- LCD_interface.h / .c – LCD functions
- Any .hex / Proteus files (if included)

---

## 🛠 Requirements

- 2x ATmega32 (or simulated in Proteus)
- I2C connection (SCL + SDA)
- 3x LED
- Proteus 8 or 9 (if simulating)
- Microcontroller programmer (if running on hardware)

---

## 🚀 How It Works

1. Master sends a number using I2C.
2. Slave receives the number.
3. If the number is 2, the LED on the slave turns on.
4.  If the number is 1, the LED on the slave turns off.

---

## 📸 Video
LED ON
https://github.com/user-attachments/assets/fb6ff681-f157-4c56-a2c6-5599fdd7642a

LED OFF

https://github.com/user-attachments/assets/35d4dfe4-05f9-4e3e-bfa6-54ed44496ed3


---

## 👩‍💻 Author

 by Fatma Elsaber
