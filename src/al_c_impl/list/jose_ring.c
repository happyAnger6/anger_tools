#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage: %s <N> <M>\r\n",argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int *pA = (int *)malloc(sizeof(int)*n);
    int i = 0;
    for(i = 0; i < n; i++)
        pA[i] = 1;

    int c = 0;
    int left = n;
    while(left>1)
    {
        i=i%n;
        if(pA[i]!=0)
        {
            c++;
            if(c==m)
            {
                printf("[%d]\r\n",i);
                pA[i]=0; 
                left--;
                c=0;
            }
        } 
        i+=1;
    }

    return 0;
}
