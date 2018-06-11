#include <curses.h>
#include <stdio.h>
#include "lib/uset.h"
#include "lib/sType.h"
#include "lib/screen.h"

//
// Data Structure

//
// Function
int getInitCh(); // Get channel when initial stage.
//
// Global Variable


int main(void)
{
	boolean loopControl = TRUE;
	int ch;

	while (loopControl )
	{
		ch = getInitCh();
		switch (ch) 
		{
			default:
		} // End of Switch	
	} // End of While
	return 0;	
}
