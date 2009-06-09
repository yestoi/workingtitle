#ifndef GAME_H
#define GAME_H

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 100 //max input

void startgame(void);
int ParseCommand(char **cmdArray, int arg, GData *dl);

enum CMD
{
    cd=1, //Change Directory
    ls, //List Directory
    rm, //Remove file/directory
    touch, //create file
    pwd, //Print Working Directory
    clear, //clear screen (require ncurses)
    _exit,
};

#endif
