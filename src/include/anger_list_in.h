#ifndef _LIST_IN_H
#define _LIST_IN_H

typedef struct ListHead_{
    struct ListHead_ *pNext, *pPrev;
}ListHead;

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
    ListHead name = LIST_HEAD_INIT(name)


static inline void INIT_LIST_HEAD(ListHead *pList)
{
        pList->pNext = pList;
        pList->pPrev = pList;
}

static inline int list_empty(ListHead *pHead)
{
        return pHead->pNext == pHead;
}

static inline void __list_add(ListHead *pNew,
                        ListHead *pPrev,
                        ListHead *pNext)
{
        pNext->pPrev = pNew;
        pNew->pNext = pNext;
        pNew->pPrev = pPrev;
        pPrev->pNext = pNew;
}

static inline void list_add(ListHead *pNew,
                    ListHead *pHead)
{
    __list_add(pNew, pHead, pHead->pNext);
}

static inline void list_add_tail(ListHead *pNew,
                        List_Head *pHead,
{
        __list_add(pNew, pHead->pPrev, pHead);
}


#endif
