#include "lib/screen.h"

#define MAX_FILE_PATH 256

//
// Data Structure

//
// Function

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
                turnOnBuffering();
                
                turnOffBuffering();
                break;
            case CH_SETOUTPUT:
                turnOnBuffering();
                
                turnOffBuffering();
                break;
            case CH_SETRES:
                turnOnBuffering();
                
                turnOffBuffering();
                break;
            case CH_SETC:
                turnOnBuffering();
                
                turnOffBuffering();
                break;
            case CH_EXEC:
                
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
