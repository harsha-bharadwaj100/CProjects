#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 50
// create a stack using struct
struct stack
{
    int top;
    int array[MAX];
};

void push(struct stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->array[++s->top] = x;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->array[s->top--];
}

int peek(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->array[s->top];
}
int main()
{
    // match paranthesis
    char expr[100];
    // create two stacks to store left and right parenthesis position
    struct stack *left = (struct stack *)malloc(sizeof(struct stack));
    struct stack *right = (struct stack *)malloc(sizeof(struct stack));

    left->top = -1;
    right->top = -1;

    printf("%s\n", "Enter an expression: ");
    scanf("%s", expr);

    int len = strlen(expr);

    // find the position of matching parenthesis and store them
    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '(')
        {
            left->array[++left->top] = i;
        }
        else if (expr[i] == ')')
        {
            right->array[++right->top] = i;
        }
    }

    if (left->top != right->top)
    {
        printf("%s\n", "Not matched");
    }
    else
    {
        printf("%s\n", "Matched");
        // print the position of matching parenthesis
        for (int i = 0; i <= left->top; i++)
        {
            printf("(%d, %d) ", left->array[i], right->array[i]);
        }
        printf("\n");
    }

    free(left);
    free(right);

    return 0;
}