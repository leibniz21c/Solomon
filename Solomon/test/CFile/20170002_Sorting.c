//
//  main.c
//  sorting
//
//  Created by knuprime096 on 2018. 6. 19..
//  Copyright © 2018년 qkd1101. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x,int *y,int z);

int main(int argc,  char * argv[])
{
    int i,j,k=0 ;
    int temp;
    int ary[50000];
    
    FILE* fp;
    if (argc != 2) {
        fprintf(stdout, "error");
        exit(1);
    }
    fp = fopen(argv[1],"r");
    
    for(i=0;i<50000;i++)
    {
        fscanf(fp,"%d",&ary[i]);
    }
    fclose(fp);
    
    for (i = 0 ;i < 50000 ;i ++)
    {
        k = ary[i];
        j = i -1;
        while(j>=0&&k<ary[j])
        {
            swap(&ary[j],&ary[j+1],temp);
            j--;
        }
        ary[j+1] = k;
    }
    
    for(i = 0 ; i < 50000;i++)
    {
        fprintf(stdout,"%d ",ary[i]);
    }
}

void swap(int *x, int *y, int z)
{
    z = *x;
    *x = *y;
    *y = z;
}
