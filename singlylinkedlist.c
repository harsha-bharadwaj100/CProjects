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

NODE insertAt(NODE head, int data, int pos)
{
    if (head == NULL || pos == 1)
    {
        head = insertFirst(head, data);
        return head;
    }
    if (pos <= size + 1 && pos > 1)
    {
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->data = data;
        NODE iter = head;
        for (int i = 1; i < pos - 1; i++)
        {
            iter = iter->next;
        }
        temp->next = iter->next;
        iter->next = temp;
        size++;
        return head;
    }
    else
    {
        printf("Invalid position\n");
        return head;
    }
}

NODE deleteAt(NODE head, int pos)
{
    if (head == NULL || pos == 1)
    {
        head = deleteFirst(head);
        return head;
    }
    if (pos <= size && pos > 1)
    {
        NODE iter = head;
        for (int i = 1; i < pos - 1; i++)
        {
            iter = iter->next;
        }
        NODE temp = iter->next;
        iter->next = temp->next;
        free(temp);
        size--;
        return head;
    }
    else
    {
        printf("Invalid position\n");
        return head;
    }
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
    int choice, data, pos;
    while (1)
    {
        printf("1. Insert First\t2. Delete First\t3. Insert Last\t4. Delete Last\t5. Insert At\t6. Delete At\t7. Display");
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
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = insertAt(head, data, pos);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = deleteAt(head, pos);
            break;
        case 7:
            display(head);
            break;
        default:
            exit(0);
        }
    }
}