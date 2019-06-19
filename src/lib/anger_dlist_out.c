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

int dlist_ins_prev(DList *pList, DListElem *pElem, void *pData)
{
   if( 0!=dlist_size(pList) && pElem == NULL)
       return -1;


   pNewElem = (DListElem *)malloc(DlistElem);
   if(NULL == pNewElem)
       return -1;

   pNewElem->pData = pData;
   if(0 == dlist_size(pList))
   {
        pList->pHead = pNewElem;
        pList->pTail = pNewElem
        pNewElem->pPrev = NULL;
        pNewElem->pNext = NULL;
   } 
   else
   {
       pNewElem->pPrev = pElem->pPrev;
       pNewElem->pNext = pElem;
       if(NULL == pElem->pPrev)
       {
            pNewElem->pPrev = NULL; 
       }
       else
       {
            pElem->pPrev->pNext = pNewElem ;
       }
       pElem->pPrev = pNewElem;

   }
   pList->iSize++;
   return 0;
}
