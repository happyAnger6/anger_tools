#include <stdio.h>
#include <stdlib.h>

int lg(int N)
{
    int i = 0;
    for(i = 0;N > 1;i++, N=N/2);

    return i;
}

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage %s <number>\r\n",argv[0]);
        return 0;
    }

    int n = atoi(argv[1]);
    printf("lg[%d]=[%d]\r\n",n,lg(n));

    return 0;
}
