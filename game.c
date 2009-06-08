#include "game.h"

void startgame(void)
{
	
	char cmdRaw[MAX_CHAR]; //input
	char **cmdList; //tokenized string

	while (1)
	{
		printf("# "); //prompt (get user info)
		fgets(cmdRaw, MAX_CHAR-1, stdin);
		cmdList = g_strsplit(cmdRaw, " ", -1);
        int i, arg;
        for (i=0;cmdList[i];i++) {
            arg = i;
        }

        ParseCommand(*cmdList, arg);
    }
}

int ParseCommand(char cmdArray[], int arg)
{
    enum CMD
    {
        cd, //Change Directory
        ls, //List Directory
        rm, //Remove file/directory
        touch, //create file
        pwd, //Print Working Directory
        clear, //clear screen (require ncurses)
    } command;

    GData *dl;
    g_datalist_init(&dl); 
    g_datalist_set_data(&dl, "cd", (gpointer) 0);
    g_datalist_set_data(&dl, "ls", (gpointer) 1);
    g_datalist_set_data(&dl, "rm", (gpointer) 2);
    g_datalist_set_data(&dl, "touch", (gpointer) 3);
    g_datalist_set_data(&dl, "pwd", (gpointer) 4);
    g_datalist_set_data(&dl, "clear", (gpointer) 5);
    
    if (arg < 1) return 0; //Don't bother with no args
    
    command = cd; 
    g_datalist_get_data(&dl, cmdArray[0]);

    switch (command)
    {
        case cd:
            printf("change directory\n");
            break;
        
        case ls:
            printf("list directory\n");
            break;

        case rm:
            printf("remove file\n");
            break;

        case touch:
            printf("create file\n");
            break;

        case pwd:
            printf("print working directory\n");
            break;

        case clear:
            printf("clear screen\n");
            break;

        default:
            break;
    }
    return 0;
}

