#include <stdio.h>
#include <stdlib.h>


typedef struct ring_array_{
    int *pArray;
    int head;
    int len;
    int cap;
}ring_array;

ring_array* init_ring_array(int cap)
{
    ring_array *pRing = (ring_array *)malloc(sizeof(ring_array));
    if(NULL == pRing)
        return NULL;

    int *pArray = (int *)malloc(sizeof(int)*cap);
    if(NULL == pArray)
        return NULL;

    pRing->pArray = pArray;
    pRing->cap = cap;
    pRing->head=0;
    pRing->len=0;

    return pRing;
}

int* ring_array_push(int data)
{
    if(pRing->len >= pRing->cap)
        return NULL;

    int idx = (pRing->head + pRing->len)%pRing->cap;
    pRing->pArray[idx]=data;
    pRing->len++;

    return &pRing->pArray[idx];
}

int* ring_array_pop()
{
    if(pRing->len == 0)
        return NULL;

    int idx = pRing->head;
    pRing->head=(pRing->head+1)%pRing->cap;
    pRing->len--;
    return &pRing->pArray[idx];
}

int main(int argc, char *argv[])
{

}
