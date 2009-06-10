#include "game.h"

/* TODO: Setup directory structure
 * TODO: Setup enviroment
 */

void startgame(void)
{
	char cmdRaw[MAX_CHAR]; //input
	char **cmdList; //tokenized string

    //Cmd lookup structure
	GData *dl;
    g_datalist_init(&dl); 
    g_datalist_set_data(&dl, "cd", (gpointer) 1);
    g_datalist_set_data(&dl, "ls", (gpointer) 2);
    g_datalist_set_data(&dl, "rm", (gpointer) 3);
    g_datalist_set_data(&dl, "touch", (gpointer) 4);
    g_datalist_set_data(&dl, "pwd", (gpointer) 5);
    g_datalist_set_data(&dl, "clear", (gpointer) 6);
    g_datalist_set_data(&dl, "exit", (gpointer) 7);

    GNode *root = g_node_new("root");
    g_node_append_data(root, "home");
    g_node_append_data(root, "etc");
    g_node_append_data(root, "lib");
    g_node_append_data(root, "proc");
    g_node_append_data(root, "bin");
    g_node_append_data(root, "dev");
    g_node_append_data(root, "usr");
    g_node_append_data(root, "var");

	while (1)
	{
		printf("# "); //prompt (get user info)

		fgets(cmdRaw, MAX_CHAR-1, stdin);
        if (cmdRaw[0] == '\n') continue; //Empty, discard
        g_strchomp(cmdRaw);
        
		cmdList = g_strsplit(cmdRaw, " ", -1);

        int i, arg;
        for (i=0;cmdList[i] != NULL;++i) {
            arg = i;
        }

        ParseCommand(cmdList, arg, dl, root);
    }
}

int ParseCommand(char **cmdArray ,int arg, GData *dl, GNode *filesystem)
{

    enum CMD command = (int) g_datalist_get_data(&dl, cmdArray[0]);

    switch (command)
    {
        case cd:
            printf("change directory\n");
            break;
        
        case ls:
            g_node_traverse(filesystem, G_IN_ORDER, G_TRAVERSE_ALL, -1, printdir, );
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

        case _exit: //gcc thinks I'm calling a function..
            g_data_destroy(dl);
            exit(EXIT_SUCCESS); //cleanup code

        default:
            printf("bash: %s: command not found\n", cmdArray[0]);
            break;
    } 
    return 0;
}

