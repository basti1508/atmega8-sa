

#include <avr/io.h>
#include <util/delay.h>

#include "../board.h"
#include "../pwm/pwm.h"
#include "../adc/adc.h"

int main()
{
	while(1)
	{
		uint8_t i = 255;
		while(i>0)
		{
			uint8_t data = readADC(0)/4;
			pwm_write(11,i);
			_delay_ms(data);
			i--;
		}
		while(i<255)
		{
			uint8_t data = readADC(0)/4;
			pwm_write(10,i);
			_delay_ms(data);
			i++;
		}
		while(i>0)
		{
			uint8_t data = readADC(0)/4;
			pwm_write(9,i);
			_delay_ms(data);
			i--;
		}
		while(i<255)
		{
			uint8_t data = readADC(0)/4;
			pwm_write(11,i);
			_delay_ms(data);
			i++;
		}
		while(i>0)
		{
			uint8_t data = readADC(0)/4;
			pwm_write(10,i);
			_delay_ms(data);
			i--;
		}
		while(i<255)
		{
			uint8_t data = readADC(0)/4;
			pwm_write(9,i);
			_delay_ms(data);
			i++;
		}

	}
}

