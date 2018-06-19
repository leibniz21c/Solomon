
#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
/* In Develope of Solomon, -1 is standard error. */
#define S_ERR -1
#define INIT_ERR -2


/* To Boolean Variable  */
#define BOOL
#define TRUE 1
#define FALSE 0

#ifdef BOOL
typedef int boolean;
#endif


/* Channel Macro. --> in screen.c, to getMenu Funtion */
#define CH_SETINPUT 1
#define CH_SETOUTPUT 2
#define CH_SETRES 3
#define CH_SETC 4
#define CH_EXEC 5
#define CH_EXIT 6


#define SOL_SET 1
#define SOL_COMBACK 0


//
// If you start this program, monitor may display initial screen.
void firstScreen();

void execScreen();

int getMenu(char * input, char * output, char * result, char * cFile);
void clearRightScreen();
void exitScreen();
