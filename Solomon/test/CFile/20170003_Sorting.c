#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[50000];

void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void quick_sort(int a[],int left,int right)
{
    
    int pivot,i,j,tmp;
    
    if(left<right)
        
    {
        
        i=left;j=right+1;
        
        pivot=a[left];
        
        while(i<j)
            
        {
            
            do
                
                i++;
            
            while((a[i]<=pivot)&&(i<right));
            
            do
                
                j--;
            
            while((a[j]>=pivot)&&(j>left));
            
            if(i<j)
                
            {
                
                tmp=a[i];
                
                a[i]=a[j];
                
                a[j]=tmp;
                
            }
            
        }
        
        if(j!=left)
            
        {
            
            tmp=a[j];
            
            a[j]=a[left];
            
            a[left]=tmp;
            
        }
        
        quick_sort(a,left,j-1);
        
        quick_sort(a,j+1,right);
        
    }
    
}


int main(int argc, char * argv[])
{
    int i;
    
    FILE* fp;
    
    if (argc != 2) {
        fprintf(stdout, "error");
        exit(1);
    }
    fp = fopen(argv[1],"r");
    
    for(i=0;i<50000;i++)
        fscanf(fp,"%d",&arr[i]);
    fclose(fp);
    
    quick_sort(arr, 0, 49999);
    
    for(i=0; i<50000; i++){
        fprintf(stdout,"%d ",arr[i]);
    }
    
    return 0;
}
