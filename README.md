# Hardware Interfacing
This repo contains the interface components written in full software layered architecture with configurable settings drivers without any built-in library.

##Sofware Layered Architecture
| Layers | Details |
| :---------- | :--------------------- |
| APP | Contains the main logic of the application |
| SERVICES | Contains the OS if there is one |
| HAL | Contains the external hardware |
| MCAL | Contains the internal hardware or peripherals |
Every layer can call the drivers from the under layers or the same layer but can't call drivers from the above layer.
> Note: there is a folder called **LIB** (Library) this folder contains utilities or files that will be used in all layers like the standard data types or bit manipulation.

## Driver Structure
Every driver has 4 files `interface.h` `config.h` `private.h` `program.c`

* **inteface.h**: this file has the prototypes of the function and the names of any custom inputs or and info I need to inform the user about it, but the user can't change anything in this file just can read it.
* **config.h**: this file has configurable settings so that the user can change them as he wants.
* **private.h**: this file has info that will be used in the `program.c` from addresses of the register and any macros or bit masking and info the user isn't interested in them.
* **programe.c**: this file has the C code of all functions.
> Note: from the previous description, we can know the the first two file `interface.h` `config.h` the user can access them or see what is inside so that he can use the driver and knows its options. and the last two file `private.h` `program.c` the user can't access them or even know what is inside.

## Compnents of MCAL
* **DIO (Digital Input/Output):** this driver is responsible for the pins used to interface with external components. The driver customizes pins' direction to be input or output and their value to be high or low.
* **GIE (Global Interrupt Enable):** the Global Interrupt (activation - deactivation) which is considered the global gate for all maskable interrupts.
* **EXTI (External Interrupt):** this drive is responsible for all External Interrupt from setting the sense control for (INT0 - INT1 - INT2) and the call back function for each interrupt so that we can put the desired function in its ISR. This driver has two options configurations pre-build configurations which you can access from settings and post-built configurations which you can access by passing your inputs to the functions.
* **ADC (Analog to Digital Converter):** this driver convert the analog signals to digital sigals.
* **TIMERS (Timer0 - Timer1 - Timer2):** this driver has 3 timers. Timer0 and Timer2 are 8-bit timers with their options and configurations. Timer2 is a 16-bit timer with its options and configurations.
* **WDT (Watchdog Timer):** the watchdog timer does one thing which is resetting the microcontroller. this driver configurable setup the settings of the watchdog timer.
* **UART (Universal Asynchronous Receiver/Transmitter):** this driver configurable setup the UART settings so that you can transmit and receive data.
* **SPI (Serial Peripheral Interface):** this driver configurable setup the SPI settings for the master node and slave node.
* **TWI (Two Wire Interface):** it's the I2C name in the ATmega32 microcontroller, this driver configurable setup the TWI settings for the master node and slave node.

## Compnents of HAL
* **LED (Light Emitting Diode):** this driver contains options that facilitate the interfacing with LEDs by giving ID to every LED so that you can turn them on/off, toggle or blink with just their ID.
* **SSD (Seven Segment):** this driver contains the configurable setup settings for the seven segments, and you can pass any number you want to be displayed in the seven segments.
* **LCD (Liquid Crystal Display):** this driver configurable setup all LCD settings to start it sends any data (char - numbers - string - custom character - commands), and selects a custom position.
* **KPD (Keypad):** this driver contains the configurable setup settings for the keypad and gets the pressed key value.
* **Motor:** this driver contains the configurable setup settings for the DC-Motor.
* **Transistor:** this driver contains the configurable setup settings for the transistor.
* **Relay:** this driver contains the configurable setup settings for the relay switches.
* **OptoCoupler:** this driver contains the configurable setup settings for the IC.
* **H_Bridge:** this driver contains the configurable setup settings for the H-Bridge.
* **ServoMotor:** this driver contains the setup settings for the Servo motor.
* **StepperMotor:** this driver contains the configurable setup settings for the Stepper motor that make you choose the angle and direction of rotation.
* **EEPROM:** interfacing with the EEPROM memory, sending and receiving data from it.
