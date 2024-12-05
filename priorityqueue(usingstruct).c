#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store an element with its priority
typedef struct
{
    int data;
    int priority;
} Element;

Element queue[MAX];
int size = 0;

// Function to insert an element into the priority queue
void enqueue(int data, int priority)
{
    if (size >= MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = size - 1;

    // Shift elements to make room for the new element by priority order
    while (i >= 0 && queue[i].priority < priority)
    {
        queue[i + 1] = queue[i];
        i--;
    }

    // Insert the new element at the found position
    queue[i + 1] = newElement;
    size++;
}

// Function to remove the element with the highest priority
void dequeue()
{
    if (size <= 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    // Highest priority element is at the start of the array
    printf("Deleted Element: %d with priority: %d\n", queue[0].data, queue[0].priority);

    // Shift all elements one position to the left
    for (int i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
    }
    size--;
}

// Function to display all elements in the priority queue
void display()
{
    if (size <= 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue Elements:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Data: %d, Priority: %d\n", queue[i].data, queue[i].priority);
    }
}

// Main function to test the priority queue
int main()
{
    int choice, data, priority;

    while (1)
    {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
