#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <str>\r\n",argv[0]);
        return -1; 
    }

    char *pcStr = argv[1];
    int len = strlen(pcStr);

    int max=0, left=0;
    int sum[256]={0};

    int tmp = 0;
    int i = 0;
    for(i=0; i<len; i++)
    {
        if(sum[pcStr[i]] == 0 || left > sum[pcStr[i]])
        {
            tmp = left - i + 1;
            if(tmp > max)
               max = tmp; 
        } 
        else
        {
            left = sum[pcStr[i]]; 
            i = left;
        }
        sum[pcStr[i]]=i+1;
    }

    printf("max len [%d]\r\n", max);
}
