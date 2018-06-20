#include "lib/screen.h"
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_FILE_PATH 256
#define MAX_INPUT_NUM 100

//
// Data Structure
void f(int signum)
{
    return;
}
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
                clearRightScreen();
                move(LINES/5+2, COLS/2+10);
                addstr("Please Wait...");
                move(LINES-1, COLS-1);
                refresh();
                execute();
    
                //                execScreen();
                
                char path[256] = {0,};
                FILE * fp;
                int i = 0, n, stu;
                char stuNum[10];
                int result;
                struct timeval howLong;
                
                if (*resultPath == '\0')
                    strcpy(path, "res/result.txt");
                else {
                    strcpy(path, resultPath);
                    strcat(path, "/result.txt");
                }
                endwin();

                fp = fopen(path, "r");
                if (fp != NULL)
                {
                    clearRightScreen();
                    move(LINES/5 +1 , COLS/2+10);
                    standout();
                    addstr("Please type any key...");
                    standend();
                    
                    fscanf(fp, "%d",&n);
                    for (i = 0 ;i < n ; i ++)
                    {
                        fscanf(fp, "%d %d %ld %d",&stu, &result, &(howLong.tv_sec),&(howLong.tv_usec));
                        sprintf(stuNum, "%d", stu);
                        move(LINES/5 +3+i, COLS/2+10);
                        addstr(stuNum);
                        move(LINES/5 +3+i, COLS/2+20);
                        addstr(":");
                        move(LINES/5 +3+i, COLS/2+22);
                        if (result)
                        {
                            addstr("Correct");
                            move(LINES/5 +3+i, COLS/2+30);
                            sprintf(path, "%ld.%d Seconds",howLong.tv_sec, howLong.tv_usec/1000);
                            addstr(path);
                        }
                        else
                            addstr("Wrong");
                    }
                    fclose(fp);
                    
                    move(LINES-1, COLS-1);
                    refresh();
                    
                    fflush(stdin);
                    getchar();
                }
            
                endwin();
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
    char cfileList2[MAX_INPUT_NUM][256];
    char cfileList3[MAX_INPUT_NUM][256];
    int i;
    char ch,chO;
    struct timeval start,end;
    
    
    if(*inputPath == '\0')
        strcpy(inputPath,"test/input.txt");
    if(*outputPath == '\0')
        strcpy(outputPath,"test/output.txt");
    
    FILE *OutFile = fopen(outputPath,"r");
    if(OutFile == NULL){
        printf("Output file open error");
        fflush(stdout);
        return;
    }
    char rPath[256];
    
    if(*resultPath == '\0')
        strcpy(rPath,"res/result.txt");
    else
        strcat(rPath,"/result.txt");
    FILE* ResFile = fopen(rPath,"w");
    if(ResFile == NULL){
        printf("Result file error");
        fflush(stdout);
        return;
    }
    
    if(*cfilePath == '\0')
        strcpy(cfilePath,"test/CFile");
    
    
    
    FILE *fp;
    
    
    if ( *cfilePath != '\0' && (c_dir = opendir(cfilePath)) != NULL )
    {
        while (( buf = readdir(c_dir) ) != NULL) {
            if (*(buf->d_name) != '.' ){
                int len = strlen(buf->d_name);
                if (buf->d_name[len-1] == 'c')
                {
                    strcpy(cfileList[input_num], cfilePath);
                    strcat(cfileList[input_num], "/");
                    strcat(cfileList[input_num], buf->d_name);
                    strcpy(cfileList2[input_num],cfileList[input_num]);
                    strcpy(cfileList3[input_num],buf->d_name);
                    input_num++;
                }
            }
        }
    }
    else
        return; // Error
    fprintf(ResFile, "%d\n",input_num);
    
    //    int cfilePathNameLen = strlen(cfilePath);
    //    char ccName[MAX_INPUT_NUM][256];
    //    for(i=0;i<MAX_INPUT_NUM;i++){
    //        char cp[1];
    //        cp[0] = i+65;
    //        strcpy(ccName[i],cp);
    //    }
    
    for(i=0;i<input_num;i++){
        int len = strlen(cfileList2[i]);
        cfileList2[i][len-2] = '\0';
    }
    int ci;
    int pid;
    
    //chdir(cfilePath);
    for(i=0;i<input_num;i++)
    {
        int isCorr = 1;
        
        if((pid = fork()) == 0)
        {
            signal(SIGINT, SIG_DFL);
            signal(SIGQUIT, SIG_DFL);
            //            printf("자식: %d\n",getpid());
            //            fflush(stdout);
            execlp("cc","cc",cfileList[i],"-o",cfileList2[i],NULL);
            exit(1);
        }
        if (pid>0)
        {
            wait(&ci);
            //            printf("부모: %d\n",pid);
            //            fflush(stdout);
            char exargv[256];
            strcpy(exargv,"./");
            
            strcat(exargv,cfileList2[i]);
            strcat(exargv," ");
            //strcat(exargv,"../input.txt");
            strcat(exargv,inputPath);
            
            fseek(OutFile,0,SEEK_SET);
            //OutFile = fopen(outputPath,"r");
            fp = popen(exargv,"r");
            if(fp == NULL){
                printf("CFile open error");
                fflush(stdout);
                return;
            }
            //int fd = popen(exargv,"r");
            
            //printf("fd : %d",fd);
            
            
            while ((ch = fgetc(fp)) != EOF) {
                chO = fgetc(OutFile);
                
                if(ch != chO){
                    isCorr = 0;
                    break;
                }
                
            }
            //End
            pclose(fp);
            
            
            if((chO = fgetc(OutFile)) != EOF)
                isCorr = 0;
            
            if(isCorr == 1){
                char tempC[40];
                strcpy(tempC, cfileList3[i]);
                for (int i = 0 ; tempC[i] != '\0' ;i ++)
                    if (tempC[i] == '_') {tempC[i] = '\0'; break;}
                fputs(tempC,ResFile);
                fflush(ResFile);
                
                gettimeofday(&start,NULL);
                int pid2 = fork();
                if(pid2 == 0){
                    close(1);
                    close(2);
                    system(exargv);
                    exit(0);
                }else if(pid2 > 0){
                    wait(&ci);
                    gettimeofday(&end,NULL);
                    
                    if (end.tv_usec < start.tv_usec)
                    {
                        end.tv_usec = start.tv_usec - end.tv_usec;
                        end.tv_sec -= 1;
                        end.tv_sec -= start.tv_sec;
                    }
                    else {
                        end.tv_sec -= start.tv_sec;
                        end.tv_usec -= start.tv_usec;
                    }
                    fprintf(ResFile," 1 %ld %d\n",end.tv_sec, end.tv_usec);
                    fflush(ResFile);
                    
                }else{
                    printf("fork error");
                }
                //exit(0);
                
                
            }else if(isCorr == 0){
                char tempC[40];
                strcpy(tempC, cfileList3[i]);
                for (int i = 0 ; tempC[i] != '\0' ;i ++)
                    if (tempC[i] == '_') {tempC[i] = '\0'; break;}
                fputs(tempC,ResFile);
                fputs(" 0 0 0\n",ResFile);
                fflush(ResFile);
            }
            //pclose(fp);
            
        }  // End of if
        else if(pid == -1)
            exit(1);
        
    }
    fclose(OutFile);
    fclose(ResFile);

}

