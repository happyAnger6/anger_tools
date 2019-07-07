#include <stdio.h>
#include <stdlib.h>

struct test{
    int i;
    short c;
    char *p;
    char s[0];
};

int main()
{
    struct test *pt = NULL;
    printf("&s = %x\r\n", pt->s);
    printf("&i = %x\r\n", &(pt->i));
    printf("&c = %x\r\n", &(pt->c));
    printf("&p = %x\r\n", &(pt->p));

    return 0;
}
