#include "game.h"
#include <stdlib.h>

/* TODO: Choose version control
 * TODO: Game Design and Planing
 */

int showmenu(void);
void loadconsole(void);

int main(void)
{
	int choice = showmenu();
	
	switch (choice) {
		case 1:
			//New Game
			loadconsole();
			startgame(); // game.c
			break;

		case 2:
			//Load Game
			break;

		case 3:
			//Exit
			exit(0); // include cleanup code later!

		default:
			break;
	}

	return 0;
}

int showmenu(void)
{
	// TODO: Draw ncurses menu
	return 1;
}

void loadconsole(void)
{
	// TODO: Init game console and draw (possibly pass controls)
}
