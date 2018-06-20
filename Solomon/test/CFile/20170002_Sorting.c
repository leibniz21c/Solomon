#include <stdio.h>

int main(int argc, char* argv[])
{
    int i ,j, tmp;
    FILE * fp;
    int ary[30000];
    
    if ( argc != 2) return 1;
    fp = fopen(argv[1], "r");
    
    for (i = 0 ;i < 30000 ;i ++)
        fscanf(fp,"%d", ary+i);
    

    
    
    for (i = 0 ;i < 30000; i++)
        printf("%d ", ary[i]);
}

