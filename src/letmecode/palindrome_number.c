#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int x)
{
    if(x<0) return 0;

    int div = 1;
    while((x/div) >= 10)
        div*=10;

    int left = 0, right = 0;
     
    while(x>0)
    {
        left = x/div;
        right = x%10;
        if(left != right) return 0;
        x=(x%div)/10;
        div=div/100;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    const char *results[] = {
        "false",
        "true"
    };

    if(argc < 2)
    {
        printf("usage:%s <number>\r\n", argv[0]);
        return -1;
    }

    int num = atoi(argv[1]);
    printf("[%d] %s\r\n", num, results[isPalindrome(num)]);
    return 0;
}
