nt roundup_pow_of_two(int num)
{
    int n = 0;
    while(num)
    {
        n++;
        num = num >> 1;
    }
    return n==0? 1 : 1<<n;
}
#include <stdio.h>
#include <stdlib.h>

int roundup_pow_of_two(int num)
{
    int n = 0;
    while(num)
    {
        n++;
        num = num >> 1;
    }
    return n==0? 1 : 1<<n;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage:%s <num>\r\n", argv[0]);
        return -1;
    }

    int num = atoi(argv[1]);
    printf("[%d]-roundup_pow:[%d]\r\n", num, roundup_pow_of_two(num)); 

    return 0;
}
