#include <stdio.h>
#include <stdlib.h>


typedef struct node_{
    int data;
    struct node_ *next;
}node;

node* add_two_list(node *p1, node *p2)
{
    node *pNew = NULL;

    int num = 0;
    int carry = 0;
    while(p1 || p2)
    {
        num = carry;
        if(p1)
        {
            num += p1->data;
            p1=p1->next;
        }

        if(p2)
        {
            num += p2->data;
            p2=p2->next;
        }

        num = num % 10;
        carry = num/10;
        node *pNode = (node *)malloc(sizeof(node));
        pNode->data = num;
        pNode->next = pNew;
        pNew = pNode;
    }

    if(carry)
    {
        node *pNode = (node *)malloc(sizeof(node));
        pNode->data = 1;
        pNode->next = pNew;
        pNew = pNode;
    }

    return pNew;
}

int main(int argc, char *argv[])
{

}
