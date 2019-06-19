#include <anger_dlist_out.h>

int dlist_ins_next(DList *pList, DListElem *pElem, void *pData)
{
    if((0 != dlist_size(pList)) && (NULL == pElem))
        return -1;

    DListElem *pNewElem = (DListElem *)malloc(DListElem);
    if(NULL == pNewElem)
        return -1;

    if(0 == dlist_size(pList))
    {
        pList->pHead = pNewElem;
        pList->pHead->pPrev = NULL;
        pList->pHead->pNext = NULL;
        pList->pTail = pNewElem;
    }
    else
    {
        pNewElem->pPrev = pElem;
        pNewElem->pNext = pElem->pNext;
        pElem->pNext->pPrev = pNewElem;
        pElem->pNext = pNewElem;
        if(pList->pTail == pElem)
        {
            pList->pTail = pNewElem; 
        }
    }

    pList->iSize++;
    return 0;

}
