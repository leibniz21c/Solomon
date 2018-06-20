#include <stdio.h>
#include <curses.h>
#include <ctype.h>
#include <stdlib.h>
#include "res.h"
#define MAX_FILE_PATH 255+1

int resPrint(char * resultPath, char * pName)
{
    FILE * fp;
    char path[MAX_FILE_PATH];
    char result[10];
    struct res buf;
    int i=0;
    
    if ( *resultPath == '\0' )
    {
        strcpy(path, "res/");
        strcat(path, "Sorting");
        strcat(path, "_res.txt");
    }
    else
    {
        strcpy(path, result);
        strcat(path, "/");
        strcat(path, "Sorting");
        strcat(path, "_res.txt");
    }
    
    fp = fopen(path, "r");
    
    move(10+(i++),COLS/2 + 5 );
    addstr("Sorting");
    while(EOF != fscanf(fp,"%s %d %ld %d",buf.stuNum,&buf.result,&buf.howLong.tv_sec,&buf.howLong.tv_usec))
    {
        move(10+(i++),COLS/2 + 5);
        addstr(buf.stuNum);
        move(10+(i),COLS/2 + 20 );
        if(buf.result==0)
            addch('0');
        else
            addch('1');
        
        /*move(10+(i++),COLS/2 + 35 );
         addstr(buf.howLong.tv_sec);
         move(10+(i++),COLS/2 + 50 );*/

        
        refresh();
        
    }
    fclose(fp);
    return 0;
    
}
void resInit(struct res * r)
{
    r->stuNum[0] = '\0';
    r->result = -1;
    r->howLong.tv_sec = 0;
    r->howLong.tv_usec = 0;
}
