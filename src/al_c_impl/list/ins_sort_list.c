#include <stdio.h>
#include <stdlib.h>

typedef struct node_{
    int data;
    struct node_ *next;
}node;


int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage: %s <n>\r\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    node *head = NULL, *tail = NULL;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = rand()%1000;
        new_node->next=NULL;
        if(NULL == head)
        {
            head=tail=new_node;
        }
        else
        {
            tail->next=new_node;
            tail=new_node;
        }
    }
    
    node *cur = head;
    i = 0;
    while(cur!=NULL)
    {
        printf("%d=[%d]\r\n",i++,cur->data);
        cur=cur->next;       
    }

    node *ins = NULL;
    node *prev = head;
    node *x = head->next;
    while(x != NULL)
    {
        ins=NULL;
        cur = head;
        while(cur->data<=x->data)
        {
            ins = cur;
            cur=cur->next;
            if(cur==x)  break;
        }

        node *tmp = x->next;
        prev->next=x->next;
        if(NULL == ins)
        {
            x->next=head;
            head=x;    
        }  
        else
        {
            x->next=ins->next;
            ins->next=x;
        }
        if(ins==prev)
        {
            prev=x;
        }
        x=tmp;
    }

    cur = head;
    i = 0;
    while(cur!=NULL)
    {
        printf("%d=[%d]\r\n",i++,cur->data);
        cur=cur->next;       
    }

    return 0;
}
