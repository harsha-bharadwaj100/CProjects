#include <stdio.h>

#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

void insert(int val)
{
    if (rear == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = val;

    printf("Inserted %d\n", val);
}

void delete()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    display();
    delete ();
    delete ();
    delete ();
    delete ();
    delete ();
    delete ();
    display();
}