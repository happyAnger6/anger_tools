#include <stdio.h>
#include <stdlib.h>


int heads()
{
    return rand() < RAND_MAX/2;
}

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage: %s <N> <M>\r\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    int *pResults = (int *)malloc((n+1)*sizeof(int));

    int i = 0, j = 0;
    for(i = 0; i <= n; i++)
        pResults[i] = 0;

    for(i = 0; i < m; i++)
    {
        int cnt = 0;
        for(j = 0; j < n; j++)
        {
            if(heads()) cnt++; 
        }
        pResults[cnt]++;
    }

    for(i = 0; i <= n; i++)
        printf("[%d]=[%d]\r\n",i,pResults[i]);

    return 0;
}
