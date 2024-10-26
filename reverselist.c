#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE insertFirst(NODE head, int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    return temp;
}

void display(NODE head)
{
    NODE temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    NODE head = NULL;
    for (int i = 5; i > 0; i--)
    {
        head = insertFirst(head, i);
    }
    printf("Before: ");
    display(head);
    NODE cur = head;
    NODE temp;
    while (cur->next != NULL)
    {
        temp = cur->next;
        cur->next = temp->next;
        temp->next = head;
        head = temp;
    }
    printf("After: ");
    display(head);
}