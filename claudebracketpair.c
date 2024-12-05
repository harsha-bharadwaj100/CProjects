#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to hold both character and its index
typedef struct
{
    char *array;
    int *indices;
    int top;
    int capacity;
} Stack;

// Function prototypes
Stack *createStack(int capacity);
void freeStack(Stack *stack);
bool push(Stack *stack, char value, int index);
bool pop(Stack *stack, int *index);
bool peek(const Stack *stack, char *value);
bool isMatchingPair(char opening, char closing);
void clearInputBuffer(void);
char *getInput(size_t *length);

int main(void)
{
    size_t length;
    char *expr = getInput(&length);
    if (!expr)
    {
        printf("Failed to get input\n");
        return 1;
    }

    // Create stack and matches array based on input length
    Stack *stack = createStack(length);
    if (!stack)
    {
        printf("Failed to create stack\n");
        free(expr);
        return 1;
    }

    // Allocate matches array dynamically
    int(*matches)[2] = malloc(length * sizeof(*matches));
    if (!matches)
    {
        printf("Failed to allocate memory for matches\n");
        freeStack(stack);
        free(expr);
        return 1;
    }

    int k = 0;
    bool isValid = true;

    for (size_t i = 0; i < length; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            if (!push(stack, expr[i], i))
            {
                printf("Stack overflow\n");
                isValid = false;
                break;
            }
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            char topChar;
            if (!peek(stack, &topChar))
            {
                printf("Invalid expression: '%c' at position %zu has no matching opening bracket\n",
                       expr[i], i);
                isValid = false;
                break;
            }

            if (isMatchingPair(topChar, expr[i]))
            {
                int openPos;
                if (pop(stack, &openPos))
                {
                    matches[k][0] = openPos;
                    matches[k][1] = i;
                    k++;
                }
            }
            else
            {
                printf("Invalid expression: '%c' at position %zu doesn't match opening bracket '%c'\n",
                       expr[i], i, topChar);
                isValid = false;
                break;
            }
        }
    }

    if (isValid && stack->top == -1)
    {
        printf("Valid expression\n");
        printf("Matches found: %d\n", k);
        for (int i = 0; i < k; i++)
        {
            printf("Pair %d: %c at position %d matches %c at position %d\n",
                   i + 1, expr[matches[i][0]], matches[i][0],
                   expr[matches[i][1]], matches[i][1]);
        }
    }
    else if (isValid)
    {
        char remainingChar;
        int remainingPos;
        peek(stack, &remainingChar);
        pop(stack, &remainingPos);
        printf("Invalid expression: '%c' at position %d has no matching closing bracket\n",
               remainingChar, remainingPos);
    }

    // Cleanup
    free(matches);
    freeStack(stack);
    free(expr);
    return 0;
}

char *getInput(size_t *length)
{
    printf("Enter an expression: ");

    // Start with a reasonable buffer size
    size_t bufsize = 128;
    char *buffer = malloc(bufsize);
    if (!buffer)
        return NULL;

    // Get the input character by character
    size_t i = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (i >= bufsize - 1)
        {
            bufsize *= 2; // Double the buffer size
            char *newBuffer = realloc(buffer, bufsize);
            if (!newBuffer)
            {
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
        }
        buffer[i++] = c;
    }

    if (i == 0 && c == EOF)
    {
        free(buffer);
        return NULL;
    }

    // Trim the buffer to actual size and add null terminator
    char *final = realloc(buffer, i + 1);
    if (!final)
    {
        free(buffer);
        return NULL;
    }
    final[i] = '\0';
    *length = i;

    return final;
}

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
        return NULL;

    stack->array = (char *)malloc(capacity * sizeof(char));
    stack->indices = (int *)malloc(capacity * sizeof(int));

    if (!stack->array || !stack->indices)
    {
        free(stack->array);
        free(stack->indices);
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

void freeStack(Stack *stack)
{
    if (stack)
    {
        free(stack->array);
        free(stack->indices);
        free(stack);
    }
}

bool push(Stack *stack, char value, int index)
{
    if (stack->top >= stack->capacity - 1)
        return false;

    stack->top++;
    stack->array[stack->top] = value;
    stack->indices[stack->top] = index;
    return true;
}

bool pop(Stack *stack, int *index)
{
    if (stack->top == -1)
        return false;

    *index = stack->indices[stack->top];
    stack->top--;
    return true;
}

bool peek(const Stack *stack, char *value)
{
    if (stack->top == -1)
        return false;

    *value = stack->array[stack->top];
    return true;
}

bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}