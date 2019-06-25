#include <stdio.h>
#include <stdlib.h>

typedef struct node_{
    int data;
    struct node_ *next;
}node;

int main(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("usage: %s <n> <m>\r\n",argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    int i = 0;
    node *head = NULL;
    node *tail = NULL;

    for(i=0; i<n; i++)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = i+1;
        if(head==NULL)
        {
            head=new_node;
            tail=head;
        }
        tail->next=new_node;
        tail=new_node;
        tail->next=head;
    } 

    i = 1;
    if(head!=NULL) printf("[%d]=%d\r\n",i++,head->data);
    node *cur = head->next;
    while(cur!=head)
    {
        printf("[%d]=[%d]\r\n", i++, cur->data);
        cur=cur->next;
    }

    node *x = tail;
    while(x->next!=x)
    {
        for(i=1;i<m;i++) x=x->next;

        printf("[%d]---[%d]\r\n", n, x->next->data);
        x->next=x->next->next;
        n--; 
    } 

    printf("[%d]\r\n",x->data);
    return 0;
}
