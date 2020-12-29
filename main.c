
#include "compiler_defs.h"
#include "C8051F380_defs.h"
#include "lcd_4bit.h"
#include "delay.h"
#include "i2c.h"
#include "lm75.h"

void Init_Device(void);

void main()
{
	int temp;
	Init_Device();
	lcd_begin();
	lcd_println("  LM75  ");

	write_lm75(0,0);// add 0-7  , control

	while(1)
	{
		temp=read_lm75(0); //add 0-7
		lcd_setCursor(2, 0);
		lcd_write(temp);

		delay_ms(100);	
	}
}
