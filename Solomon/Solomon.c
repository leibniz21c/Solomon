#include "lib/screen.h"
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_FILE_PATH 256
#define MAX_INPUT_NUM 100

//
// Data Structure

//
// Function
void terminalSetting(int how);
void execute();
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
        channel = getMenu(inputPath, outputPath, resultPath, cfilePath);
        switch (channel) {
            case CH_SETINPUT:
                clearRightScreen();
                
                move(10, COLS/2 + 5);
                
                addstr("Input Path(name) ? ");
                
                getstr(inputPath);
                //addstr(inputPath);        //for test ok
                
                refresh();
                
                //sleep(5);
                endwin();
                
                break;
            case CH_SETOUTPUT:
                clearRightScreen();
                
                move(10, COLS/2 + 5);
                
                addstr("Output Path(name) ? ");
                getstr(outputPath);
                //addstr(outputPath);       //for test ok
                refresh();
                
                //sleep(5);
                endwin();
                
                break;
            case CH_SETRES:
                clearRightScreen();
                
                move(10, COLS/2 + 5);
                
                addstr("Result File Path ? ");
                getstr(resultPath);
                //addstr(outputPath);       //for test ok
                refresh();
                
                //sleep(5);
                endwin();
                break;
            case CH_SETC:
                clearRightScreen();
                
                move(10, COLS/2 + 5);
                
                addstr("C File Directory Path ? ");
                getstr(cfilePath);
                //addstr(outputPath);       //for test ok
                refresh();
                
                //sleep(5);
                endwin();
                break;
            case CH_EXEC:
                //                terminalSetting(SOL_COMBACK);
                //                execScreen();
                execute();
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
void execute()
{
    DIR * c_dir = NULL;
    struct dirent * buf;
    int input_num=0;
    char cfileList[MAX_INPUT_NUM][256];
    int i;
    
    if ( *cfilePath != '\0' && (c_dir = opendir(cfilePath)) != NULL )
    {
        while (( buf = readdir(c_dir) ) != NULL) {
            if (*(buf->d_name) != '.' ){
                strcpy(cfileList[input_num], cfilePath);
                strcat(cfileList[input_num], "/");
                strcat(cfileList[input_num], buf->d_name);
                input_num++;
            }
        }
    }
    else
        return; // Error
    
    for(i=0;i<input_num;i++)
    {
        if(fork() == 0)
        {
            execlp("cc","cc",cfileList[i],"-o","test/CFile/temp",NULL);
            exit(0);
        }
        
    }
    
}
