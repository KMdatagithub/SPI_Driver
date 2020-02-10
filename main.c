/*
 * SPI_Driver.c
 *
 * Created: 2/9/2020 3:24:41 PM
 * Author : Khaled Magdy
 */ 
#include "softwareDelay.h"
#include "interrupt.h"
#include "gpio.h"
#include "timers.h"
#include "SPI.h"


static volatile uint8_t SPI_Data = 0x00;


// SPI Master Test Code
/*
int main(void)
{
    SPI_Init(SPI_Master, SPI_CLK_F_64, SPI_Mode0, LSB_First, SPI_Interrupts_Disabled);
	uint8_t counter=0;
    while (1) 
    {
		SPI_Write(counter++);
		softwareDelayMs(250);
    }
}
*/


// SPI Slave Test Code

int main(void)
{
    SPI_Init(SPI_Slave, SPI_CLK_F_64, SPI_Mode0, LSB_First, SPI_Interrupts_Enabled);
	gpioPortDirection(GPIOD, OUTPUT);
	gpioPortWrite(GPIOD, 0x00);
    while (1) 
    {
		// Stay IDLE ...
    }
}
ISR(SPI_STC_vect)
{
	SPI_Data = SPDR;
	gpioPortWrite(GPIOD, SPI_Data);
}
