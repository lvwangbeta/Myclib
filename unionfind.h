#ifndef UNIONFIND_H_INCLUDED
#define UNIONFIND_H_INCLUDED
#define N 8
typedef int SetType;        //int if use array, pointer if tree(maybe)
typedef int ElementType;    //


extern void Initiallize(ElementType *a);
extern void SetUnion(ElementType *a, SetType root1, SetType root2);
extern SetType Find(ElementType *a, ElementType x);

#endif // UNIONFIND_H_INCLUDED
