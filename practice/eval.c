#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
float S[MAX];
int top = -1;
void push(float value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    S[++top] = value;
}

// Function to pop an element from the stack
float pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return (S[top--]);
}

// Function to get the top element of the stack
float peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return S[top];
}

int main()
{
    char post[MAX] = "231*+9-3/1+";
    float a, b;
    for (int i = 0; post[i] != '\0'; i++)
    {
        if (isdigit(post[i]))
        {
            push(post[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();
            switch (post[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
                // case '^':
                //     push(b ^ a);
                //     break;
            }
        }
    }

    printf("%f\n", pop());
}