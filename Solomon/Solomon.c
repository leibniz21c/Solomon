#include "lib/screen.h"

#define MAX_FILE_PATH 256

//
// Data Structure

//
// Function
void terminalSetting(int how);
// import

// In this C file
void initStr(char * str);
void turnOnBuffering(void);
void turnOffBuffering(void);

//
// Global Variable
char inputPath[MAX_FILE_PATH];
char outputPath[MAX_FILE_PATH];
char resultPath[MAX_FILE_PATH];
char cfilePath[MAX_FILE_PATH];

int main(void)
{
    int channel;
    
    
    initStr(inputPath);
    initStr(outputPath);
    initStr(resultPath);
    initStr(cfilePath);
    
    firstScreen();
    
    while ( TRUE )
    {
        channel = getMenu();
        switch (channel) {
            case CH_SETINPUT:
                clearRightScreen();
                
                move(10, COLS/2 + 5);
                
                addstr("Input way ? ");
                
                getstr(inputPath);
                //addstr(inputPath);        //for test ok
                
                refresh();
                
                //sleep(5);
                endwin();
                
                break;
            case CH_SETOUTPUT:
                clearRightScreen();
                
                move(10, COLS/2 + 5);
                
                addstr("Output way ? ");
                getstr(outputPath);
                //addstr(outputPath);       //for test ok
                refresh();
                
                //sleep(5);
                endwin();
                
                break;
            case CH_SETRES:
                clearRightScreen();
                turnOnBuffering();
                
                turnOffBuffering();
                break;
            case CH_SETC:
                clearRightScreen();
                turnOnBuffering();
                
                turnOffBuffering();
                break;
            case CH_EXEC:
                terminalSetting(SOL_COMBACK);
                execScreen();
                break;
            case CH_EXIT:
                terminalSetting(SOL_COMBACK);
                exitScreen();
                break;
            default:
                break;
        }
    }
    
}
void initStr(char * str)
{
    *str = '\0';
}
void turnOnBuffering()
{
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag |= ICANON;
    t.c_cc[VMIN] = 255;
    tcsetattr(0, TCSANOW, &t);
}
void turnOffBuffering()
{
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ICANON;
    t.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &t);
}
void terminalSetting(int how)
{
    static struct termios backup;
    struct termios new_setting;
    
    if (how == SOL_SET)
    {
        tcgetattr(0, &new_setting);
        tcgetattr(0, &backup);
        
        new_setting.c_lflag &= ~ECHO;
        new_setting.c_lflag &= ~ICANON;
        new_setting.c_cc[VMIN] = 1;
        
        tcsetattr(0 , TCSANOW, &new_setting);
        
        //
        // Signal
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
    }
    else if (how == SOL_COMBACK)
    {
        tcsetattr(0 , TCSANOW, &backup);
        
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
    }
}
