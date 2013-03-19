#include "basiclib.h"
#include "mem.h"
#include "array.h"
#include "arrayrep.h"
#define T Array_T
//Array_T是结构体指针
/*
*Array_new 和  Array_free 也达到了充分的解耦
*因为其具体实现都交给了二层接口Array_init
*/
T Array_new(int length, int size)
{
    T array;
    NEW(array);
    if(length > 0)
    {
        Array_init(array, length, size, ALLOC(length, size));
    }
    else
    {
        Array_init(array, length, size, NULL);
    }
    return array;
}
void Array_free(T *array)       //指向(结构体)指针的指针
{
    assert(array && (*array));
    Free((*array)->array);
    Free(*array);
}
int Array_length(T array)
{
    assert(array);
    return array->length;
}

void Array_init(T array, int length, int size, void *arr)
{
    assert(array);
    assert((length>0 && arr) || (length<0 && arr==NULL));
    assert(size);
    array->length = length;
    array->size = size;
    if(length > 0)
        array->array = arr;
    else
        array->array = NULL;
}

int Array_size(T array)
{
    assert(array);
    return array->size;
}
                                        //get返回索引为index的元素的指针
void *Array_get(T array, int index)     //之所以返回void型指针也是为了较高的通用性
{                                       //与具体实现的类型解耦
    assert(array);
    assert(index >= 0 && index < array->length);
    return array->array + index*array->size;
}

void Array_put(T array, int index, void *x) //覆盖index位置处元素
{
    assert(array);
    assert(index >= 0 && index < array->length);
    memcpy(array->array + index * array->size, x, array->size);

}

