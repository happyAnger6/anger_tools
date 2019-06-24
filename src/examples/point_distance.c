#include <stdio.h>
#include <stdlib.h>

#include <math.h>

typedef struct {
    float x;
    float y;
}point;


float random_float()
{
    return 1.0*rand()/RAND_MAX;
}

float distance(point x, point y)
{
    float a = x.x - y.x;
    float b = x.y - y.y;
    return sqrt(abs(a*a - b*b));
}

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage %s <point_num> <distance>\r\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    float d = atof(argv[2]);
    point *pPoints = (point *)malloc(n*sizeof(point));
    int i = 0;
    for(i = 0; i < n; i++)
    {
        pPoints[i].x = random_float();
        pPoints[i].y = random_float();
    }

    int j = 0;
    int cnt = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(distance(pPoints[i],pPoints[j])<d)
                cnt++; 
        }
    
    }

    printf("%d edges shorter than %f\n", cnt, d);
    return 0;

}
