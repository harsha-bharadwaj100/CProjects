#include <stdio.h>
#include <string.h>

int main()
{

    char expr[100];
    int pairs[100][2];

    printf("Enter an expression: ");
    scanf("%s", expr);

    int len = strlen(expr);

    // find the position of matching parenthesis and store them
    int j = 0, left = 0, right = 0;
    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '(')
        {
            pairs[j][0] = i;
            j++;
            left++;
        }
        else if (expr[i] == ')')
        {
            pairs[j - 1][1] = i;
            j--;
            right++;
        }
    }
    if (left != right)
    {
        printf("Invalid expression\n");
        return 0;
    }
    // Print the result
    for (int i = 0; i < left; i++)
    {
        printf("(%d, %d) ", pairs[i][0], pairs[i][1]);
    }
    printf("\n");
    return 0;
}