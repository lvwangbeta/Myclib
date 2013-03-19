#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define T Tree_Node

typedef struct T *T;
extern void inorder(T p);
extern void preorder(T p);
extern void postorder(T p);
extern void level_order(T p);
extern void insert(T *p, int value);
extern T newtree(int arr[], int n);

#undef T
#endif // TREE_H_INCLUDED
