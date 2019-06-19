#include <stdio.h>
#include <stdlib.h>
#include <anger_list_out.h>

void list_init(List *pList, ListElemDestoryPf pfDestory)
{
    pList->iSize = 0;
    pList->pHead = NULL;
    pList->pTail = NULL;
    pList->pfDestory = pfDestory;

    return;
}

void _list_ins_head(List *pList, ListElem *pElem)
{
    if(NULL == pList->pHead)
    {
        pList->pTail = pElem;
    }
    
    pElem->pNext = pList->pHead;
    pList->pHead = pElem;
}

int list_ins_next(List *pList, ListElem *pInsert, void *pData)
{
        if(NULL == pList)
            return;

        ListElem *pNewElem = NULL;
        pNewElem = (ListElem *)malloc(sizeof(ListElem));
        if(NULL == pNewElem)
            return -1;
        
        pNewElem->pData = pData;
        pNewElem->pNext = NULL;
        if(NULL == pInsert)
        {
                _list_ins_head(pList, pNewElem); 
        }
        else
        {
                if(pInsert->pNext == NULL)
                    pList->pTail = pNewElem;
                pNewElem->pNext = pInsert->pNext; 
                pInsert->pNext = pNewElem;
        }

        pList->iSize++;
        return 0;
}

ListElem* _list_del_head(List *pList, void **ppData)
{
    ListElem *pDel = pList->pHead->pNext;
    pList->pHead = pDel->pNext;
    if(NULL == pDel->pNext) //last elem
    {
        pList->pTail = NULL;
    }
    *ppData = pDel->pData;
    return pDel;
}

int list_del_next(List *pList, ListElem *pDel, void **ppData)
{
    ListElem *pElem = NULL;
    if(NULL == pList->pHead)
        return -1;

    if(NULL == pDel)
    {
        pElem = _list_del_head(pList, ppData);
    }
    else
    {
        pElem = pDel->pNext;
        if(NULL == pElem)
        {
            return -1;
        }
        pDel->pNext = pElem->pNext;
        if(NULL == pElem->pNext)
            pList->pTail = pDel;
        *ppData = pElem->pData;
    }

    free(pElem);
    pList->iSize--;
    
    return 0;
}

void list_destory(List *pList)
{
    if(0 == pList->iSize)
        return;

    void *pData;
    ListElem *pElem;
    while(pList->iSize>0)
    {
        list_del_next(pList, NULL, &pData);
        pList->pfDestory(pData);
    }

    memset(pList, 0, sizeof(List));
    return;
}
