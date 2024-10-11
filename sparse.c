#include <stdio.h>

int main()
{
    int sparseMatrix[10][10]; // Original matrix
    int triplet[100][3];      // Triplet format: (row, column, value)
    int rows, cols;           // Dimensions of the sparse matrix
    int nonZeroCount = 0;     // Count of non-zero elements

    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input the sparse matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &sparseMatrix[i][j]);
            // If the element is non-zero, store it in triplet format
            if (sparseMatrix[i][j] != 0)
            {
                triplet[nonZeroCount][0] = i;                  // Row index
                triplet[nonZeroCount][1] = j;                  // Column index
                triplet[nonZeroCount][2] = sparseMatrix[i][j]; // Value
                nonZeroCount++;
            }
        }
    }

    // Display the triplet format
    printf("\nTriplet Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++)
    {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    return 0;
}