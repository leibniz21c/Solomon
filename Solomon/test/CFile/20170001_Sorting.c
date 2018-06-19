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

int main()
{
    int i = 0 ;
    int j = 0 ;
    int temp = 0;
    int temp2 = 0;
    int ary[50000];
    FILE* fp;
    fp = fopen("input.txt","r");
    
    for(i=0;i<50000;i++)
    {
        fscanf(fp,"%d",&ary[i]);
    }
    
    fp = fopen("outputSelection.txt","w");
    
    for (i = 0 ;i < 50000-1 ;i ++)
    {
        temp = i;
        
        for (j = i+1 ;j < 50000 ;j ++)
            if (ary[temp] > ary[j])
            {
                temp = j;
            }
        swap(&ary[i],&ary[temp],temp2);
    }
    
    for(i = 0 ; i < 50000;i++)
    {
        fprintf(fp,"%d ",ary[i]);
    }
}

void swap(int *x, int *y, int z)
{
    z = *x;
    *x = *y;
    *y = z;
}
