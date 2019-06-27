typedef struct node_{
    int data;
    struct node_ *left;
    struct node_ *right;
}node;

void pre_traverse(node *pRoot)
{
    queue = [pRoot];
    while(node=queue.pop())
    {
        traverse(node);
        queue.append(node->left);
        queue.append(node->right);
    }
}

void rm_left_node(node *pNode)
{
    node *rm_node = pNode->left;
    if(rm_node == NULL)
        return;

    node *left = rm_node->left;
    node *father = NULL;
    if(left)
    {
        while(left->right)
        {
            father=left;
            left=left->right;
        }

        if(father!=NULL)
        {
            father->right=NULL;
        }
        pNode->left = left;
        left->right=rm_node->right;
        return;
    }

    node *right = rm_node->right;
    fahter = NULL;
    if(right)
    {
        while(right->left)
        {
            father = right;
            right=right->left;
        } 
        if(father!=NULL)
            father->left = NULL;

        pNode->left = right;
        right->right = rm_node->right;
    }
}
