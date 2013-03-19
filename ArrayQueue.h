#ifndef ARRAYQUEUE_H_INCLUDED
#define ARRAYQUEUE_H_INCLUDED
#define T ArrayQueue
typedef int QueueElementType;
typedef struct T *T;

T AQ_CreateQueue(int capacity);
void AQ_MakeEmpty(T queue);
void AQ_Enqueue(T queue, QueueElementType value);
void AQ_Dequeue(T queue);
QueueElementType AQ_Front(T queue);            //get the front value but not dequeue
QueueElementType AQ_FrontAndDequeue(T queue);
int AQ_isEmpty(T queue);
int AQ_isFull(T queue);

#undef T
#endif // ARRAYQUEUE_H_INCLUDED
