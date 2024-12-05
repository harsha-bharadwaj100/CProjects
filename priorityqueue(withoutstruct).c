#include <stdio.h>
#define MAX 100

int queue[MAX];
int priority[MAX];
int size = 0;

void insert(int element, int prio)
{
    if (size == MAX)
    {
        printf("Queue is full.\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && priority[i] < prio)
    {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }
    queue[i + 1] = element;
    priority[i + 1] = prio;
    size++;
}

void delete()
{
    if (size == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Deleted element with highest priority: %d (Priority: %d)\n", queue[0], priority[0]);
    for (int i = 1; i < size; i++)
    {
        queue[i - 1] = queue[i];
        priority[i - 1] = priority[i];
    }
    size--;
}

void display()
{
    if (size == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element: %d, Priority: %d\n", queue[i], priority[i]);
    }
}

int main()
{
    int choice, element, prio;
    while (1)
    {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            printf("Enter priority of the element: ");
            scanf("%d", &prio);
            insert(element, prio);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}