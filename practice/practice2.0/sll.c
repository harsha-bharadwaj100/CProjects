#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE head = NULL;

void insertFront()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = head;
    head = temp;
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    NODE temp = head;
    head = head->next;
    free(temp);
}

void insertEnd()
{
    int data;
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Entre data: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    NODE cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    if (head->next == NULL)
    {
        NODE cur = head;
        head = NULL;
        free(cur);
        return;
    }
    NODE cur = head;
    while (cur->next->next != NULL)
    {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

void insertAt()
{
    int pos, data;
    printf("Enter pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertFront();
        return;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    NODE cur = head;
    for (int i = 1; i < pos - 1; i++)
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
}

void display()
{
    NODE cur = head;
    printf("List: ");
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void search()
{
    int data;
    printf("enter data: ");
    scanf("%d", &data);
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    NODE cur = head;
    int pos = 1;
    while (cur != NULL)
    {
        if (cur->data == data)
        {
            printf("Element found at positon %d!\n", pos);
            return;
        }
        cur = cur->next;
        pos++;
    }
    printf("Element Not Found");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. insertFront\n2. deleteFront\n3. insertEnd\n4. deleteEnd\n5. insertAt\n6. display\n7. search\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFront();
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            insertAt();
            break;
        case 6:
            display();
            break;
        case 7:
            search();
            break;
        default:
            printf("Exiting...\n");
            return 1;
        }
    }
}