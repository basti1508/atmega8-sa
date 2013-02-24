/*
 * Copyright (c) 2013 Sebastian Himmler
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#include <avr/io.h>

#include "board.h"
#include "pwm.h"


void pwm_write(const uint8_t pin, uint8_t val)
{
        switch(pin)
        {
		case 9:
			DDRB |= (1 << PB1);
			TCCR1A |= (1 << COM1A1) | (1 << WGM10);
			TCCR1B |= (1 << CS11) | (1 << WGM12);
			OCR1A=val;
			break;
		case 10:
			DDRB |= (1 << PB2);
			TCCR1A |= (1 << COM1B1) | (1 << WGM10);
			TCCR1B |= (1 << CS11) | (1 << WGM12);
			OCR1B=val;
			break;
		case 11:
			DDRB |= (1 << PB3);
			TCCR2 |= (1 << COM21) | (1 << WGM20) | (1 << CS20);
			OCR2=val;
			break;
	}
}
