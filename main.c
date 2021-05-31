#include <stdio.h>
#include <string.h>
#include <switch.h>


PrintConsole *console;

int main (int argc, char **argv) {
	
	console = consoleGetDefault();
	consoleInit(console);
	
	PadState pad;
	padConfigureInput(1, HidNpadStyleSet_NpadFullCtrl);
	padInitializeAny(&pad);
	
	printf("hello world!");
	consoleUpdate(console);
	
	while (appletMainLoop()) {

		padUpdate(&pad);

		u64 kDown = padGetButtonsDown(&pad);

		if (kDown & KEY_PLUS)
			break;
	}
	
    consoleExit(console);	
	return 0;
}
