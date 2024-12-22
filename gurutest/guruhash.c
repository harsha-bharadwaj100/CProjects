#include <stdio.h>
#include <string.h>

#define SIZE 10

struct emp
{
    char name[50];
    int key;
} ht[SIZE] = {0};

// Function prototypes
int lprob(int k);
int qprob(int k);

int main()
{
    char name[50];
    int key, location, k;
    FILE *fp;

    // Open the file for reading
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // Read records from the file and insert them into the hash table
    while (fscanf(fp, "%s %d", name, &k) == 2)
    {
        location = lprob(k); // Use lprob(k) for linear probing or qprob(k) for quadratic probing
        strcpy(ht[location].name, name);
        ht[location].key = k;
    }
    fclose(fp);

    // Display the hash table contents
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (ht[i].key != 0)
        { // Print only non-empty entries
            printf("Index %d: Key = %d, Name = %s\n", i, ht[i].key, ht[i].name);
        }
        else
        {
            printf("Index %d: Empty\n", i);
        }
    }

    return 0;
}

// Function for Linear Probing
int lprob(int k)
{
    int location = k % SIZE;
    while (ht[location].key != 0)
    {                                     // Continue probing until an empty spot is found
        location = (location + 1) % SIZE; // Wrap around the table
    }
    return location;
}

// Function for Quadratic Probing
int qprob(int k)
{
    int location = k % SIZE;
    int i = 0; // Iteration counter
    while (ht[location].key != 0)
    { // Continue probing until an empty spot is found
        i++;
        location = (k + i * i) % SIZE; // Quadratic probing formula
    }
    return location;
}