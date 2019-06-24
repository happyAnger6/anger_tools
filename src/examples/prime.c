#include <stdio.h>
#include <stdlib.h>

#define N 1000
int main()
{
    int a[N];
    int i = 0, j = 0;
    for(i = 0; i < N; i++)
    {
        a[i]=1;
    } 

    for(i=2;i<N;i++)
    {
        if(a[i])
        {
            for(j=i;i*j<N;j++)
            {
                    a[i*j]=0;
            }
        }
    }

    for(i=2;i<N;i++)
        if(a[i]) printf("%d\n",a[i]);

    return 0;
}
