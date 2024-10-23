#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
int stack[MAX], top = -1;

void push(int ele)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    stack[++top] = ele;
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    if (top == -1)
    {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}