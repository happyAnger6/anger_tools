#ifndef _ANGER_LIST_OUT_H
#define _ANGER_LIST_OUT_H

typedef struct ListElem_{
    void *pData;
    struct ListElem_ *pNext;
}ListElem;

typedef void (*ListElemDestoryPf)(void *pData);
typedef struct List_{
    int iSize;
    void (*pfMatch)(const void *pKey1, const void *pKey2);
    void (*pfDestory)(void *pData);
    ListElem *pHead;
    ListElem *pTail;
}List;

void list_init(List *pList, ListElemDestoryPf pDestory);
void list_destory(List *pList);
int list_ins_next(List *pList, ListElem *pInsert, const void *pData);
int list_del_next(List *pList, ListElem *pDel, void **ppData);

#define list_head(pList) ((pList)->pHead)
#define list_tail(pList) ((pList)->pTail)
#define list_is_head(pList, pElem) ((pList)->pHead == (pElem)? 1 : 0)
#define list_is_tail(pList, pElem) ((pList)->pTail== (pElem)? 1 : 0)
#define list_data(pElem) ((pElem)->pData)
#define list_next(pElem) ((pElem)->pNext)

#endif
