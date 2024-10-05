#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *NODE;

NODE insertFirst(NODE head, int data)
{
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    return temp;
}

NODE deleteFirst(NODE head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void insertLast(NODE head, int data)
{
    if (head == NULL)
    {
        head = insertFirst(head, data);
        return;
    }
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    NODE iter = head;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = temp;
}

void display(NODE head)
{
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp = head;
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
    int data;
    while (1)
    {
        printf("1. Insert First\n2. Delete First\n3. Display\n4. Insert Last\n");
        printf("Enter your choice: ");
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
            display(head);
            break;
        case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            insertLast(head, data);
            break;
            return 0;
        default:
            exit(0);
        }
        printf("----------------------\n");
    }
}