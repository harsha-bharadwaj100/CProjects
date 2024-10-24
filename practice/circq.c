#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Max size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull()
{
    return ((rear + 1) % MAX == front);
}

// Function to check if the queue is empty
int isEmpty()
{
    return (front == -1);
}

// Function to add an element to the queue
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full. Overflow!\n");
        return;
    }

    if (isEmpty()) // If the queue is initially empty
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX; // Circular increment
    }

    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an element from the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Underflow!\n");
        return;
    }

    printf("Removed %d\n", queue[front]);

    if (front == rear) // Queue becomes empty after dequeue
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX; // Circular increment
    }
}

// Function to display the front element (peek)
void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display all elements in the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, value;

    do
    {
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
