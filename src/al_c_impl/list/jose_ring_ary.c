#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage: %s <N> <M>\r\n",argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    int *pA = (int *)malloc(n*sizeof(int));
    int i = 0;
    for(i = 0; i < n; i++)
    {
        pA[i]=(i+1)%n;
    }

    for(i = 0; i < n; i++)
    {
        printf("[%d].next=[%d]\r\n", i, pA[i]);
    }

    int prev = n-1;
    int h = 0;
    int cnt = 0;
    while(h!=pA[h])
    {
        cnt++;
        if(cnt==m)
        {
            printf("[%d]\r\n",h);
            pA[prev] = pA[h]; 
            cnt=0;
        }
        else
        {
            prev=h;
        }
        h=pA[h];
    }
    return 0;
}
