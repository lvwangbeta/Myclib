#ifndef ARRAYREP_H_INCLUDED
#define ARRAYREP_H_INCLUDED
/*
*Together, Array and ArrayRep
*illustrate a two-level interface or a layered interface. Array specifies a
*high-level view of an array ADT, and ArrayRep specifies another, more
*detailed view of the ADT at a lower level. The advantage of this organiza-
*tion is that importing ArrayRep clearly identifies those clients that
*depend on the representation of dynamic arrays. Changes to the repre-
*sentation thus affect only them, not the presumably much larger popula-
*tion of clients that import Array.
*arrayrep.h为二层接口定义了动态数组的具体数据结构
*/


#define T Array_T

struct T
{
    int length;             //数组中的元素个数
    int size;               //每个元素的大小
    char *array;
};

//Array_init()依赖于数组的表示
//即可能只包含在引用了该接口的客户端中
extern void Array_init(T array, int length, int size, void *arr);

#undef T
#endif // ARRAYREP_H_INCLUDED
