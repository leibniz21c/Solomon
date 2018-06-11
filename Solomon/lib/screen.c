#include <curses.h>
#include "sType.h"

//
// If you start this program, monitor may display initial screen.
void firstScreen()
/* if you want to continue, you have to press just any one key. */
{	
	// initial Setting
	initscr();
	clear();
	
	// Writing
	move(LINES/2-1 , COLS/2 - 3);
	standout();
	addstr("Solomon");
	standend();

	move(LINES/2, COLS/2 - 5);
	addstr("version 1.0");
	move(LINES/2 + 2, COLS/2 - 10 );
	addstr("Please press any key");
	
	move(LINES-1 ,0);
	addstr("Made by KNU group. 2018 OpenSourceProgramming Teamwork");
	

	move(LINES-1, COLS-1);
	getch(); // get 1 char.
	endwin();		
}

int getMenu()
/*  get menu screen.  								         */
/*  exit --> 0(CH_EXIT) , set user info --> CH_USET, get user info --> CH_HIST(history)  */
{
	int i;
	int ch = -1;

	// inital Setting
	initscr();
	clear();

	// Writing
	for (i = 0 ;i < LINES ;i ++) { move(i, COLS/2); addstr("|"); } // middle line
	
	// left side screen
	move(10, 20);
	addstr("*");
	while ( ! isControlKey(ch) )
	{
		
		refresh();
		
	}

	getch();
	endwin();
	return 0;
}
int isControlKey(char ch)
{
	
}

int main(void)
{/* For test */
	firstScreen();
	getMenu();

	return 0;
}
