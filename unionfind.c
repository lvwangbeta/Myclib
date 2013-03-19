#include "basiclib.h"
#include "unionfind.h"

extern void Initiallize(ElementType *a)
{
    int i;
    for(i=1; i<=N; i++)
        a[i] = 0;
}

/*
*按高度求并
*/
extern void SetUnion(ElementType *a, SetType root1, SetType root2)
{
    if(a[root2] < a[root1])
    {
        a[root1] = root2;
    }
    else
    {
        if(a[root1] == a[root2])
        {
            a[root1]--;
        }
        a[root2] = root1;
    }
}
extern SetType Find(ElementType *a, ElementType x)
{
    if(a[x] < 0)
        return x;
    else
        return Find(a, a[x]);
}
