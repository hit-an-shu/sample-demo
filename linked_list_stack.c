#include<stdio.h>
#include<stdlib.h>

/* Comment */

typedef int ItemType;
typedef enum{FAILURE, SUCCESS} StatusCode;
typedef enum{False, True} Boolean;
typedef struct NodeTag
{
    ItemType data;
    struct NodeTag* next;
}Node;
typedef struct StackTag
{
    Node* top;
}Stack;

void InitializeStack(Stack* stack_ptr)
{
    stack_ptr->top = NULL;
}

Boolean isStackEmpty(Stack* stack_ptr)
{
    Boolean retval;

    if(stack_ptr->top == NULL)
    {
        retval = True;
    }
    else
    {
        retval = False;
    }
    return retval;
}

StatusCode Push(ItemType elmnt, Stack* stack_ptr)
{
    Node* nptr;
    StatusCode retval = SUCCESS;

    nptr = (Node*) malloc(sizeof(Node));

    if(nptr == NULL)
    {
        retval = FAILURE;
    }
    else
    {
        nptr->data = elmnt;
        nptr->next = stack_ptr->top;
        stack_ptr->top = nptr;
    }
    return retval;
}

StatusCode Pop(ItemType* eptr, Stack* stack_ptr)
{
    StatusCode retval = SUCCESS;
    Node* nptr;

    if(isStackEmpty(stack_ptr))
    {
        retval = FAILURE;
    }
    else
    {
        nptr = stack_ptr->top;
        *eptr = nptr->data;
        stack_ptr->top = (stack_ptr->top)->next;
        free(nptr);
    }
    return retval;
}

int main()
{
    Stack stck;
    StatusCode sc;
    ItemType elmnt;
    InitializeStack(&stck);
    sc = Push(10, &stck);
    sc = Push(20, &stck);
    sc = Push(30, &stck);
    sc = Pop(&elmnt, &stck); printf("%d \n", elmnt);
    sc = Pop(&elmnt, &stck); printf("%d \n", elmnt);

    return 0;
}
