#ifndef _STACK_H
#define _STACK_H

#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destory list_destory

int stack_push(Stack *pStack, const void *pData);
int stack_pop(Stack *pStack, void **ppData);

#define stack_peek(pStack) ((pStack)->pHead == NULL? NULL : (pStack)->pHead->pData)

#define stack_size list_size

#endif
