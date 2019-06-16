#include "slist.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    slist *pHead = NULL;



}

void reverse_slist(slist **ppHead)
{
    if(NULL == *ppHead)
        return;

    slist *pHead = *ppHead;
    slist *pCur = pHead->pNext;
    slist *pPrev = pHead;
    while(NULL != pCur)
    {
        slist *pTmp = pCur->pNext;
        pCur->pNext = pPrev;
        pPrev = pCur;
        pCur = pTmp;
    }

    pHead->pNext = NULL;
    *ppHead = pPrev;
    return;
}
