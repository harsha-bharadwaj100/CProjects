#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *NODE;

NODE getNode()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    NODE new = (NODE)malloc(sizeof(struct node));
    new->data = data;
    new->next = new->prev = new;
    return new;
}

NODE insertFront(NODE tail)
{
    NODE new = getNode();
    if (tail == NULL)
        return new;
    new->next = tail->next;
    new->prev = tail;
    tail->next->prev = new;
    tail->next = new;
    return tail;
}

NODE deleteFront(NODE tail)
{
    if (tail == NULL || tail->next == tail)
    {
        free(tail);
        return NULL;
    }
    NODE temp = tail->next;
    tail->next = temp->next;
    tail->next->prev = tail;
    free(temp);
    return tail;
}

NODE insertEnd(NODE tail)
{
    NODE new = getNode();
    if (tail == NULL)
        return new;
    new->prev = tail;
    new->next = tail->next;
    tail->next->prev = new;
    tail->next = new;
    tail = new;
    return tail;
}

NODE deleteEnd(NODE tail)
{
    if (tail == NULL || tail->next == tail)
    {
        free(tail);
        return NULL;
    }
    NODE temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    return temp;
}

void display(NODE tail)
{
    if (tail == NULL)
    {
        printf("Empty\n");
        return;
    }
    if (tail->next == tail)
    {
        printf("%d\n", tail->data);
        return;
    }
    NODE current = tail->next;
    while (current != tail)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

int main()
{
    NODE tail = NULL;
    int choice;
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tail = insertFront(tail);
            break;
        case 2:
            tail = deleteFront(tail);
            break;
        case 3:
            display(tail);
            break;
        case 4:
            tail = insertEnd(tail);
            break;
        case 5:
            tail = deleteEnd(tail);
            break;
        default:
            printf("Exit");
            exit(0);
        }
    }

    return 0;
}
