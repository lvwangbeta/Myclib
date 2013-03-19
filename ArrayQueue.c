#include "basiclib.h"
#include "ArrayQueue.h"
#define T ArrayQueue

struct T
{
    int capacity;
    int front;
    int rear;
    int size;
    QueueElementType *array;
};

T AQ_CreateQueue(int capacity)
{
    T queue = MALLOC(sizeof(struct T));
    queue->array = MALLOC(sizeof(QueueElementType) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    return queue;
}
void AQ_MakeEmpty(T queue)
{
    queue->size = 0;
    queue->front = queue->rear = 0;
}
//enter the queue
void AQ_Enqueue(T queue, QueueElementType value)
{
    if(AQ_isFull(queue))
    {
        fprintf(stderr, "The queue is full\n");
        return;
    }
    else
    {
        queue->size++;
        queue->array[queue->rear] = value;
        queue->rear = (queue->rear+1)%queue->capacity;
    }
}
//out the queue
void AQ_Dequeue(T queue)
{
    if(AQ_isEmpty(queue))
    {
        fprintf(stderr, "The queue is empty\n");
        return;
    }
    else
    {
        queue->size--;
        queue->front = (queue->front+1)%queue->capacity;

    }
}
//get the first node of the queue, not delete
QueueElementType AQ_Front(T queue)            //get the front value but not dequeue
{
    if(AQ_isEmpty(queue))
    {
        printf("The queue is empty\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        return queue->array[queue->front];
    }
}
//out the queue and get the node
QueueElementType AQ_FrontAndDequeue(T queue)
{
    QueueElementType data = AQ_Front(queue);
    AQ_Dequeue(queue);
    return data;
}
int AQ_isEmpty(T queue)
{
    return queue->size == 0;
}
int AQ_isFull(T queue)
{
    return queue->size == queue->capacity;
}
