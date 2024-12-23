#include <stdio.h>
#include <stdlib.h>
// Implementaion of sparse matrix
#define MAX 10
int main()
{
    int matrix[MAX][MAX];
    int rows, cols;
    int triplet[MAX * MAX][3];

    printf("Enter the number of rows and columns of the matrix: ");
    fflush(stdout);
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                triplet[count][0] = i;
                triplet[count][1] = j;
                triplet[count][2] = matrix[i][j];
                count++;
            }
        }
    }

    printf("Triplet Representation:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}