#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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
    temp->next = temp;
    temp->data = data;
    return temp;
}

void insertFirst()
{
    if (last == NULL)
    {
        last = getNode();
        return;
    }
    NODE new = getNode();
    new->next = last->next;
    last->next = new;
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
        free(temp);
        last = NULL;
        return;
    }
    NODE cur = last->next;
    while (cur->next != last)
    {
        cur = cur->next;
    }
    NODE temp = last;
    cur->next = last->next;
    last = cur;
    free(temp);
}

void display()
{
    NODE cur = last->next;
    while (cur != last)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d ", last->data);
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. InsertFront\n2. DeleteEnd\n3. Display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFirst();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            display();
            break;
        default:
            return 0;
        }
    }
}