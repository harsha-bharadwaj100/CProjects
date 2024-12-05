#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;

NODE head = NULL;
int size = 0;
NODE getNode(int data)
{
    NODE new = (NODE)malloc(sizeof(struct node));
    new->data = data;
    new->next = new->prev = NULL;
    return new;
}

NODE insertFront()
{
    int info;
    printf("Enter data: ");
    scanf("%d", &info);
    NODE temp = getNode(info);
    if (head == NULL)
    {
        size++;
        return temp;
    }
    head->prev = temp;
    temp->next = head;
    size++;
    return temp;
}

NODE deleteFront()
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        size--;
        return NULL;
    }
    NODE temp = head->next;
    free(head);
    temp->prev = NULL;
    size--;
    return temp;
}

void display()
{
    NODE cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
NODE insertEnd()
{
    if (head == NULL)
    {
        return insertFront();
    }
    NODE cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    NODE temp = getNode(data);
    cur->next = temp;
    temp->prev = cur;
    size++;
    return head;
}

NODE deleteEnd()
{
    if (head == NULL || head->next == NULL)
    {
        return deleteFront();
    }
    NODE cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    NODE temp = cur->prev;
    free(cur);
    temp->next = NULL;
    size--;
    return head;
}

NODE insertAt()
{
    int pos, data;
    printf("Enter position (1 - %d): ", size + 1);
    scanf("%d", &pos);
    if (pos == 1)
    {
        return insertFront();
    }
    if (pos == size + 1)
    {
        return insertEnd();
    }
    if (pos < 1 && pos > size + 1)
    {
        printf("Invalid Position!\n");
        return head;
    }
    NODE cur = head;
    for (int i = 1; i < pos - 1; i++)
    {
        cur = cur->next;
    }
    printf("Enter Data: ");
    scanf("%d", &data);
    NODE temp = getNode(data);
    temp->prev = cur;
    temp->next = cur->next;
    cur->next->prev = temp;
    cur->next = temp;
    size++;
    return head;
}

NODE deleteAt()
{
    int pos;
    printf("Enter position (1 - %d): ", size);
    scanf("%d", &pos);
    if (pos < 1 || pos > size)
    {
        printf("Invalid position\n");
        return head;
    }
    if (pos == 1)
    {
        return deleteFront();
    }
    else if (pos == size)
    {
        return deleteEnd();
    }
    NODE cur = head;
    for (int i = 1; i < pos - 1; i++)
    {
        cur = cur->next;
    }
}

void search()
{
    int data, pos = -1;
    printf("Enter data: ");
    scanf("%d", &data);
    NODE cur = head;
    while (cur->next != NULL)
    {
        pos++;
        if (cur->data == data)
        {
            printf("Found at position %d\n", pos + 1);
        }
        cur = cur->next;
    }
    if (pos == -1)
    {
        printf("Data not found\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert Front\t2. Delete Front\t3. Display\t4. Insert At\t5. Delete At\t6. Insert End\t7. Delete End\t8. Search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertFront();
            break;
        case 2:
            head = deleteFront();
            break;
        case 3:
            display();
            break;
        case 4:
            head = insertAt();
            break;
        case 5:
            head = deleteAt();
            break;
        case 6:
            head = insertEnd();
            break;
        case 7:
            head = deleteEnd();
            break;
        case 8:
            search();
            break;
        default:
            printf("Exiting...");
            exit(0);
        }
    }
}