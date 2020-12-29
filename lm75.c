//************* lm75 ***********

#include "i2c.h"

#define LM75_address 0x48 //0x48-0x4F  , 100_1xxx

bit write_lm75(U8 devAdr,U8 outchar)
{
	bit ask=1;
	Wire_start();
	if(!Wire_write((LM75_address + devAdr)<<1))  // 1001xxx0 
	{
		ask=Wire_write(outchar);
	}
	Wire_stop();
	return ask; //if ask=0 data ok
}


U16 read_lm75(U8 devAdr)
{

	U16 in_int = 0;
	Wire_start();
	if(!Wire_write(((LM75_address+devAdr)<<1)|1))  // 1001xxx1 
	{
		in_int=Wire_read(0) << 8;  //0-  ack from master 
		in_int+=Wire_read(1);  //1- read byte and finish no ack
		in_int=(in_int>>5)/8;  //* 0.125
	}
	Wire_stop();
	return in_int;		
}
