#include "game.h"

void startgame(void)
{
	/* TODO: Set up directory structure
	 * TODO: Implement command parsing  */
	
	char cmdRaw[MAX_CHAR]; //input
	char **cmdList; //tokenized string
	
	while (1)
	{
		printf("# "); //prompt (get user info)
		fgets(cmdRaw, MAX_CHAR-1, stdin);
		cmdList = g_strsplit(cmdRaw, " ", -1);

        int i;
        for (i=0; cmdList[i]; i++) {
            printf("|%s", cmdList[i]);
        }
    }
}
