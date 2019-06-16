#ifndef _SLIST_H
#define _SLIST_H

typedef struct slist_{
    struct slist_ *pNext;
    void *pData; 
}slist;

#endif
