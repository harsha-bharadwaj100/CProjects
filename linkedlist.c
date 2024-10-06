#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *NODE;

void insertFirst(NODE *head, int data)
{
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void deleteFirst(NODE *head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void insertLast(NODE *head, int data)
{
    if (*head == NULL)
    {
        insertFirst(NULL, data);
        return;
    }
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    NODE iter = *head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = temp;
}

void deleteLast(NODE *head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    NODE iter = *head;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    free(iter->next);
    iter->next = NULL;
    return;
}

void insertAt(NODE *head, int data, int pos)
{
    if (*head == NULL)
    {
        insertFirst(NULL, data);
        return;
    }
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->data = data;
    NODE iter = *head;
    for (int i = 0; i < pos - 1 && iter->next != NULL; i++)
    {
        iter = iter->next;
    }
    temp->next = iter->next;
    iter->next = temp;
    return;
}

void deleteAt(NODE *head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        deleteFirst(head);
        return;
    }
    NODE iter = *head;
    for (int i = 0; i < pos - 1 && iter->next->next != NULL; i++)
    {
        iter = iter->next;
    }
    NODE temp = iter->next;
    iter->next = temp->next;
    free(temp);
    return;
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

int main()
{
    NODE head = NULL;
    int choice;
    int data, pos;
    while (1)
    {
        printf("1. Insert First\n2. Delete First\n3. Display\n4. Insert Last\n5. Delete Last\n6. Insert At\n7. Delete At\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertFirst(&head, data);
            break;
        case 2:
            deleteFirst(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            insertLast(&head, data);
            break;
            return 0;
        case 5:
            deleteLast(&head);
            break;
        case 6:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAt(&head, data, pos);
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAt(&head, pos);
            break;
        default:
            exit(0);
        }
        printf("----------------------\n");
    }
}