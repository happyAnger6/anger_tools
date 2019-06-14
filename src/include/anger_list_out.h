#ifndef _ANGER_LIST_OUT_H
#define _ANGER_LIST_OUT_H

typedef struct ListElem_{
	void *pData;
	struct ListElem_ *pNext;
}ListElem;

typedef void (*pfDestory)(void *pData) ListElemDestoryPf;
typdef struct List_{
    int iSize;
    void (*pfMatch)(const void *pKey1, const void *pKey2);
    void (*pfDestory)(void *pData);
    ListElem *pHead;
    ListElem *pTail;
}List;

void list_init(List *pList, ListElemDestoryPf pDestory);
void list_destory(List *pList);
int list_ins_next(List *pList, ListElem *pInsert, const void *pData);
int list_rem_next(List *pList, ListElem *pRemove, void **ppData);
#endif
