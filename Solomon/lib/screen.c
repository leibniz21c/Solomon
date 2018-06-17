#include "screen.h"



// Gloval Variable
int x, y;




//
// If you start this program, monitor may display initial screen.
void firstScreen()
/* if you want to continue, you have to press just any one key. */
{
//    terminalSetting(SOL_SET,NULL);
    
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
/*  get menu screen.                                           */
{
    int i, ch = 1;
    char mv = 0;
    //  0->set directory,   1->set input,  2->set output,  3->set result,
    // 4->set C file,  5-> execute,    6-> exit
    //
    // CH_SETDIR, CH_SETINPUT,  CH_SETOUTPUT,  CH_SETRES, CH_SETC, CH_EXEC, CH_EXIT
    //
    
    // inital Setting
    initscr();
    clear();
    
    
    // Lines Writing
    for (i = 5 ;i < LINES-5 ;i ++) { move(i, COLS/2); addch('|'); } // middle line
    for (i = 5 ;i < COLS-5 ;i ++) {move(5, i); addch('-'); } // top line
    for (i = 5 ;i < COLS-5 ;i ++) {move(LINES-5, i); addch('-'); }
    for (i = 6 ;i < LINES-5 ;i ++) {move(i, 5); addch('|');}
    for (i = 6 ;i < LINES-5 ;i ++) {move(i, COLS-5); addch('|');}
    
    move(7, 10);
    addstr("< Please Type W, S for move cursor >");
    
    
    // left side screen
    move(12, 15);
    addstr("->");
    
    //
    // Menu
    x = 10;
    y = 18;
    move(x+2, y);
    addstr("Set Input File");
    move(x+4, y);
    addstr("Set Output File");
    move(x+6, y);
    addstr("Set Result File Path");
    move(x+8, y);
    addstr("Set C File Path");
    move(x+10, y);
    addstr("Execute");
    move(x+12, y);
    addstr("Exit");
    
    x = 12;
    y = 15;
    
    while ( TRUE  )
    {
        move(LINES-1, COLS-1);
        mv = getch();
        move(LINES-1, COLS-1);
        
        if (mv == '\n')
            switch (ch)
        {
            case 1: {endwin();return CH_SETINPUT;}
            case 2: {endwin();return CH_SETOUTPUT;}
            case 3: {endwin();return CH_SETRES;}
            case 4: {endwin();return CH_SETC;}
            case 5:{endwin(); return CH_EXEC;}
            case 6:{ endwin(); return CH_EXIT;}
            default: {endwin();return S_ERR;}
        }
        else
        {
            switch (mv)
            {
                case 's': case'S':
                    if (ch == 6)    break;
                    else {
                        ch++;
                        move(x,y);
                        addstr("  ");
                        x += 2;
                        move(x, y);
                        addstr("->");
                        move(LINES-1, COLS-1);
                    }
                    break;
                    
                case 'w':case'W':
                    if (ch == 1) break;
                    else {
                        ch--;
                        move(x,y);
                        addstr("  ");
                        x -= 2;
                        move(x, y);
                        addstr("->");
                        move(LINES-1, COLS-1);
                    }
                    break;
                default:
                    break;
            }
        }
        
        refresh();
        
    } // End of While
    
    refresh();
    endwin();
    
    return 0;
}

void clearRightScreen()
/*  get menu screen.                                           */
{
    int i, ch = 1;
    char mv = 0;

    
    // inital Setting
    initscr();
    clear();
    
    
    // Lines Writing
    for (i = 5 ;i < LINES-5 ;i ++) { move(i, COLS/2); addch('|'); } // middle line
    for (i = 5 ;i < COLS-5 ;i ++) {move(5, i); addch('-'); } // top line
    for (i = 5 ;i < COLS-5 ;i ++) {move(LINES-5, i); addch('-'); }
    for (i = 6 ;i < LINES-5 ;i ++) {move(i, 5); addch('|');}
    for (i = 6 ;i < LINES-5 ;i ++) {move(i, COLS-5); addch('|');}
    
    move(7, 10);
    addstr("< Please Type W, S for move cursor >");
    
    
    // left side screen
    //
    // Menu
    x = 10;
    y = 18;
    move(x+2, y);
    addstr("Set Input File");
    move(x+4, y);
    addstr("Set Output File");
    move(x+6, y);
    addstr("Set Result File Path");
    move(x+8, y);
    addstr("Set C File Path");
    move(x+10, y);
    addstr("Execute");
    move(x+12, y);
    addstr("Exit");
    
    refresh();

}
void execScreen()
{
    char inputName[20];
    clear();
    
        int i;
        for (i = 10 ;i < LINES-10 ;i ++) { move(i, 10); addch('|'); } // middle line
        for (i = 10 ;i < COLS-10 ;i ++) {move(10, i); addch('-'); }
        for (i = 10 ;i < LINES-10 ;i ++) { move(i, COLS-10); addch('|'); } // middle line
        for (i = 10 ;i < COLS-10 ;i ++) {move(LINES-10, i); addch('-'); }// top line
        move(LINES/2,11);
        addstr("Input File Name?");
        move(LINES/2,28);
        refresh();
        fgets(inputName,20,stdin);
    
    
    
    
}

void exitScreen()
{
//    terminalSetting(SOL_COMBACK);
    // initial Setting
    clear();
    
    // Writing
    move(LINES/2-1 , COLS/2 - 3);
    standout();
    addstr("Solomon");
    standend();
    
    move(LINES/2, COLS/2 - 5);
    addstr("version 1.0");
    move(LINES/2 + 2, COLS/2 - 10 );
    addstr("Thank you! Termination ...");
    
    move(LINES-1 ,0);
    addstr("Made by KNU group. 2018 OpenSourceProgramming Teamwork");
    refresh();
    
    move(LINES-1, COLS-1);
    sleep(3);
    endwin();
    exit(0);
}
