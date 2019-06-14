#include <stdio.h>
#include <stdlib.h>
#include <anger_list_out.h>

int list_ins_next(List *pList, ListElem *pInsert, void *pData)
{
        if(NULL == pList)
            return;

        pNewElem = (ListElem *)malloc(sizeof(ListElem));
        if(NULL == pNewElem)
            return;
        pNewElem->pData = pData;
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
}
