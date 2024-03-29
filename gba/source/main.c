#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <gba_sio.h>
#include <gba.h>
#include <stdio.h>
#include <stdlib.h>

// (c)FIX94
//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// only enable serial irq for SI_Transfer
	irqInit();
	irqEnable(IRQ_SERIAL);

	// disable this, needs power
	REG_DISPCNT = LCDC_OFF;
	SNDSTAT = 0;
	SNDBIAS = 0;

	// send over data until we turn it off
	while (1) {
		REG_JOYTR_L = REG_KEYINPUT;
		Halt();
	}
}