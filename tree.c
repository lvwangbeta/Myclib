#include "basiclib.h"
#include "tree.h"
#include "mem.h"

#define T Tree_Node
#define MAX_QUEUE_SIZE 100

struct T
{
    int data;
    T left;
    T right;
};

void inorder(T p)
{
    if(p)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void preorder(T p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(T p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
void level_order(T p)
{
    int front, rear;
    front = rear = 0;
    T queue[MAX_QUEUE_SIZE];
    if(!p) return ;             //empty tree
    queue[rear++] = p;
    while(front < rear)
    {
        T ptr = queue[front++];
        if(ptr)
        {
            printf("%d ", ptr->data);
            if(ptr->left)
                queue[rear++] = ptr->left;
            if(ptr->right)
                queue[rear++] = ptr->right;
        }
    }
}
void insert(T *p, int value)
{
    //empty tree
    if(*p == NULL)
    {
        (*p) = MALLOC(sizeof(struct T));
        (*p)->data = value;
        (*p)->left = (*p)->right = NULL;
        return ;
    }
    if(value < (*p)->data)
    {
        insert(&((*p)->left), value);
    }
    else if(value > (*p)->data)
    {
        insert(&((*p)->right), value);
    }
}

T newtree(int arr[], int len)
{
    int i;
    T tree = NULL;
    if(!arr)
    {
        Error("arr can not be empty\n");
    }
    for(i=0; i<len; i++)
        insert(&tree, arr[i]);
    return tree;
}

