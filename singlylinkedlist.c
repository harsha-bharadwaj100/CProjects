// Menu driven Implemetaion of singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE head = NULL;
int size = 0;

NODE insertFirst(NODE head, int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    size++;
    return head;
}

NODE deleteFirst(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE temp = head;
    head = head->next;
    free(temp);
    size--;
    return head;
}

NODE insertLast(NODE head, int data)
{
    if (head == NULL)
    {
        head = insertFirst(head, data);
        return head;
    }
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    NODE iter = head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = temp;
    size++;
    return head;
}

NODE deleteLast(NODE head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List is empty\n");
        head = deleteFirst(head);
        return head;
    }
    NODE iter = head;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    free(iter->next);
    iter->next = NULL;
    size--;
    return head;
}

void display(NODE head)
{
    NODE temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    int choice, data;
    while (1)
    {
        printf("1. Insert First\t2. Delete First\t3. Insert Last\t4. Delete Last\t5. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertFirst(head, data);
            break;
        case 2:
            head = deleteFirst(head);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertLast(head, data);
            break;
        case 4:
            head = deleteLast(head);
            break;
        case 5:
            display(head);
            break;
        default:
            exit(0);
        }
    }
}