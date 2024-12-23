#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;

void enqueue()
{
    if (rear == MAX - 1)
    {
        printf("Overflow!\n");
        return;
    }
    int data;
    printf("Enter data");
    scanf("%d", &data);
    queue[++rear] = data;
    if (front == -1)
        front++;
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow!\n");
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
        return;
    }
    front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("Enter choice: ");
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
            return 0;
        }
    }
}