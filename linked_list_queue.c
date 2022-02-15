#include<stdio.h>
#include<stdlib.h>

/* Change Made */

typedef int ItemType;
typedef enum{FAILURE, SUCCESS} StatusCode;
typedef enum{False, True} Boolean;
typedef struct NodeTag
{
    ItemType data;
    struct NodeTag* next;    
}Node;
typedef struct QueueTag
{
    Node* front;
    Node* rear;
}Queue;

void InitializeQueue(Queue* qptr)
{
    qptr->front = NULL;
    qptr->rear = NULL;
}

Boolean isQueueEmpty(Queue* qptr)
{
    Boolean retval;
    if(qptr->front == NULL && qptr->rear == NULL)
    {
        retval = True;
    }
    else
    {
        retval = False;
    }
    return retval;
}

StatusCode InsertQueue(ItemType elmnt, Queue* qptr)
{
    StatusCode retval = SUCCESS;
    Node* nptr;
    nptr = (Node*) malloc(sizeof(Node));

    if(nptr == NULL)
    {
        retval = FAILURE;
    }
    else
    {
        nptr->data = elmnt;
        nptr->next = NULL;
        if(isQueueEmpty(qptr))
        {
            qptr->front = nptr; qptr->rear = nptr;
        }
        else
        {
            (qptr->rear)->next = nptr;
            qptr->rear = nptr;
        }
    }
    return retval;
}

StatusCode DeleteQueue(ItemType* eptr, Queue* qptr)
{
    StatusCode retval = SUCCESS;
    Node* nptr;
    if(isQueueEmpty(qptr))
    {
        retval = FAILURE;
    }
    else
    {
        nptr = qptr->front;
        *eptr = nptr->data;

        qptr->front = (qptr->front)->next;
        if(qptr->front == NULL)
        {
            qptr->rear = NULL;
        }
        free(nptr);
    }
    return retval;
}

int main()
{
    Queue myQueue;
    ItemType element;
    StatusCode sc;
    InitializeQueue(&myQueue);
    sc = InsertQueue(10, &myQueue);
    sc = InsertQueue(20, &myQueue);
    sc = InsertQueue(30, &myQueue);
    sc = DeleteQueue(&element, &myQueue); printf("\n %d \n", element);
    
    return 0;
}
