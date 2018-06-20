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
    
    for (i = 0 ;i < 30000 ;i ++)
        for (j = i+1 ; j < 30000 ;j ++)
            if( ary[i]> ary[j])
            {
                tmp = ary[i];
                ary[i] = ary[j];
                ary[j] = tmp;
            }
    
    for (i = 0 ;i < 30000; i++)
        printf("%d ", ary[i]);
}
