#include <stdio.h>
#define MAX 10
int matrix[MAX][MAX], triplet[MAX * MAX][3];

int main()
{
    int rows, cols;
    printf("Enter the number of rows and colums: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // printf("Sparse Matrix:\n");
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("Triplet Form:\n");
    printf("row\tcol\tvalue\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
    return 0;
}