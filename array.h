#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

/*
*该接口定义的动态数组的通用方法
*为一级接口
*/
#define T Array_T
typedef struct T *T;                    //struct Array_T中封装了动态数组的指针（*）
                                        //客户端可根据具体情况申请不同的数据结构来表示动态数组
extern T Array_new(int length, int size);
extern void Array_free(T *array);       //指向(结构体)指针的指针
extern int Array_length(T array);
extern int Array_size(T array);
                                            //get返回索引为index的元素的指针
extern void *Array_get(T array, int index); //之所以返回void型指针也是为了较高的通用性
                                            //与具体实现的类型解耦

extern void Array_put(T array, int index, void *x); //覆盖index位置处元素

#undef T


#endif // ARRAY_H_INCLUDED
