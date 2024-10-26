#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char parastack[MAX];
int indices[MAX];
int top = -1;

void push(char value, int index)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    parastack[top] = value;
    indices[top] = index;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return indices[top--];
}

char peek()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return parastack[top];
}

int main()
{
    char expr[MAX];
    int matches[MAX][2];
    printf("Enter an expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    int k = 0;
    int left = 0, right = 0;
    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            push(expr[i], i);
            left++;
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            right++;
            if (peek() == '(' && expr[i] == ')' || peek() == '[' && expr[i] == ']' || peek() == '{' && expr[i] == '}')
            {
                matches[k][0] = pop();
                matches[k][1] = i;
                k++;
            }
        }
    }

    if (top == -1 && left == right)
    {
        printf("Valid expression\n");
        printf("Matches: %d\n", k);
        for (int i = 0; i < k; i++)
        {
            printf("%c%d, %d%c\n", expr[matches[i][0]], matches[i][0], matches[i][1], expr[matches[i][1]]);
        }
    }
    else
    {
        printf("Invalid expression\n");
    }
    return 0;
}