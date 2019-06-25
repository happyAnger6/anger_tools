#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int data;
    struct node_ *next;
}node;

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage:%s <N>\r\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    int i = 0;
    node *head = NULL, *tail = NULL;

    for(i=0;i<n;i++)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data=i+1;
        if(head==NULL)
        {
            head=tail=new_node;
            tail->next=head;
            continue;
        }
        
        new_node->next=head;
        tail->next=new_node;
        tail=new_node;
    }

    i = 1;
    node *cur = head;
    while(cur->next!=head)
    {
        printf("%d=[%d]\r\n",i++,cur->data);
        cur=cur->next;
    }
    printf("%d=[%d]\r\n",i,cur->data);

    if(head==NULL)
        return;

    node *prev=head; 
    cur=head->next;
    while(cur!=head)
    {
        node *tmp = cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }

    head->next=cur; 
    head=prev;
    tail=head;

    for(i=0;i<n;i++)
    {
        printf("[%d]=[%d]\r\n",i,head->data);
        head=head->next;
    }

    return 0;

}
