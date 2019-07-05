#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 10;
    int *pa = &a;
    typeof(pa) pb = &b;

    printf("*pb=[%d]\r\n", *pb);

    return 0;
}
