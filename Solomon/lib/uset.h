/* user_setting library  */
/* made by YJ            */

#define MAX_NAME 30 //maximum length of user name
#define MAX_LIST 100
#define MAX_PNAME 50 //maximum length of file name
#define USET_PATH "bin/uset.bin" //default path

#include <sys/time.h>
#include <sys/types.h>

struct info{
    char* pname[MAX_PNAME];
    struct timeval when;
    struct timeval howLong; //executing time
    size_t howMany; //memory size
};

struct uset{
    char* u_name[MAX_NAME]; //user name
    struct info g_info[MAX_LIST];
    int g_cnt;
};

void usetInit(struct uset*); //name = "NONAME", g_cnt = 0
