#include <sys/time.h>
#include <string.h>

struct res {
    char stuNum[10];
    int result;
    struct timeval howLong;
};

int resPrint(char * resultPath, char * pName);
void resInit(struct res * r);
