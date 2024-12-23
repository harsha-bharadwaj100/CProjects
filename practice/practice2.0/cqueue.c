#include <stdio.h>

#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue()
{
    if ((rear + 1) % MAX == front)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        rear = (rear + 1) % MAX;
        queue[rear] = data;
    }
    if (front == -1)
        front = 0;
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
        return;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue\n");
        return;
    }
    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}

void main()
{
    int choice;
    while (1)
    {
        printf("Enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            return;
        }
    }
}