#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node *NODE;

NODE last = NULL;

NODE getNode()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = temp->next = temp;
    return temp;
}

void insertFront()
{
    if (last == NULL)
    {
        last = getNode();
        return;
    }
    NODE temp = getNode();
    NODE first = last->next;
    temp->next = first;
    temp->prev = last;
    first->prev = temp;
    last->next = temp;
    return;
}

void deleteFirst()
{
    if (last == NULL)
    {
        printf("Empty list\n");
        return;
    }
    if (last->next == last)
    {
        NODE temp = last;
        last = NULL;
        free(temp);
        return;
    }
    NODE first = last->next;
    if (first->next == last)
    {
        last->next = last->prev = last;
        free(first);
        return;
    }
    last->next = first->next;
    free(first);
    return;
}

void insertEnd()
{
    if (last == NULL)
    {
        last = getNode();
        return;
    }
    NODE first = last->next;
    NODE temp = getNode();
    temp->next = first;
    temp->prev = last;
    first->prev = temp;
    last->next = temp;
    last = temp;
    return;
}

void deleteEnd()
{
    if (last == NULL)
    {
        printf("Empty list\n");
        return;
    }
    if (last->next == last)
    {
        NODE temp = last;
        last = NULL;
        free(temp);
        return;
    }
    NODE first = last->next;
    first->prev = last->prev;
    last->prev->next = first;
    NODE temp = last;
    last = last->prev;
    free(temp);
    return;
}

void display()
{
    if (last == NULL)
    {
        printf("Empty list\n");
        return;
    }
    NODE cur = last->next;
    while (cur != last)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d\n", cur->data);
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. insertFront\n2. deleteFront\n3. insertEnd\n4. deleteEnd\n5. display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFront();
            break;
        case 2:
            deleteFirst();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            display();
            break;
        default:
            printf("Exiting...\n");
            return 0;
        }
    }
}