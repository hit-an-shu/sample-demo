#include<stdio.h>
#include<stdlib.h>

/* changes made */
/* ALL FUNCTIONS ARE IN THIS FILE */

struct Node
{
    int data;
    struct Node* next;
};

struct Node* CreateList(int num)
{
    struct Node *lptr, *nptr;
    int i;
    lptr = NULL; nptr = NULL;
    for (i = 1; i <= num ; i++)
    {
        nptr = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter a data element: "); scanf("%d", &nptr->data);
        nptr->next = lptr;
        lptr = nptr;
    }
    return lptr;
}

void DeleteList(struct Node* lptr)
{
    struct Node* nptr;
    while(lptr != NULL)
    {
        nptr = lptr;
        lptr = lptr->next;
        free(nptr);
    }
}

void Traverse(struct Node* lptr)
{
    struct Node* ptr;
    ptr = lptr;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void question1(struct Node* lptr)
{
    if(lptr == NULL)
    {
        return;
    }
    question1(lptr->next);
    printf("%d ", lptr->data);
}

struct Node* question2(struct Node* lptr, int n) /* this is assuming that n is less than the size of linked list */
{
    struct Node *ptr1, *ptr2;
    ptr1 = lptr; ptr2 = lptr;
    int i = 0;
    while(i < n)
    {
        ptr1 = ptr1->next;
        i++;
    }
    while(ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}

struct Node* question3(struct Node* lptr)
{
    struct Node* ptr;
    ptr = lptr;
    if(lptr != NULL || lptr->next != NULL)
    {
        while((ptr->next)!= NULL) /* reach last node */
        {
            ptr = ptr->next;
        }
        ptr->next = lptr;
        lptr = ptr; /* circular linked list achieved */
        while((ptr->next)!= lptr) /* reach new last node */
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;

    }
    return lptr;
}

void question4(struct Node* lptr)
{

}

struct Node* question5(struct Node* lptr) /* some error */
{
    struct Node *prev, *ptr, *end;
    prev = NULL; ptr = lptr; end = NULL;
    if(lptr != NULL)
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        end = ptr;
        ptr = lptr;

        while(ptr != NULL)
        {
            if((ptr->data)%2 == 0)
            {
                if(prev == NULL)
                {
                    lptr = lptr->next;
                }
                else
                {
                    prev->next = ptr->next;
                }
                ptr->next = NULL;

                end->next = ptr; end = end->next;



                if(prev == NULL)
                {
                    ptr = lptr;
                }
                else
                {
                    ptr = prev->next;
                }
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
    return lptr;

}

int main()
{
    struct Node* lptr;
    lptr = CreateList(6); printf("\n");

    Traverse(lptr); printf("\n");
    question1(lptr); printf("\n");
    lptr = question3(lptr);
    Traverse(lptr); printf("\n");


    DeleteList(lptr);

    return 0;
}
