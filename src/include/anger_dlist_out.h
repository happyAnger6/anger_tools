#ifndef _ANGER_DLIST_OUT_H
#define _ANGER_DLIST_OUT_H

typedef struct DListElem_
{
    void *pData;
    struct DlistElem_ *pPrev;
    struct DlistElem_ *pNext;
}DListElem;

typedef struct DList_
{
    int size;
    int (*match)(const void *pKey1, const void *pKey2);
    void (*destory)(void *pData);
    DListElem *pHead;
    DListElem *pTail;
}DList;
#endif
