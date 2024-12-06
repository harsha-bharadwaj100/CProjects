#include <stdio.h>
#include <string.h>

struct employee
{
    char name[50];
    int key;
} hashTable[10];

int lprobe(int key)
{
    int index = key % 10;
    while (hashTable[index].key != 0)
    {
        index = (index + 1) % 10;
    }
    return index;
}

int qprobe(int key)
{
    int index = key % 10;
    int i = 0;
    while (hashTable[index].key != 0)
    {
        index = (index + i * i) % 10;
        i++;
    }
    return index;
}

// Main function
void main()
{
    int i, loc, k, choice; // Variables
    char name[50];         // Array to store the name of the employee
    FILE *fp;              // File pointer to read data from the file

    // Step 1: Initialize the hash table
    for (i = 0; i < 10; i++)
    {
        hashTable[i].key = 0;           // 0 indicates an unused slot
        strcpy(hashTable[i].name, " "); // Initialize names with an empty string
    }

    // Step 2: Open the file for reading
    fp = fopen("practice/employee.txt", "r"); // Open file in read mode
    if (fp == NULL)
    {
        printf("File not found"); // Check if the file exists
        return;                   // Exit if the file cannot be opened
    }

    // Step 3: Choose the hashing method
    printf("choose the hashing method\n1. Linear Probing\n2. Quadratic Probing\n");
    scanf("%d", &choice); // Take user input for the hashing method

    // Step 4: Read data from the file and insert into the hash table
    while (fscanf(fp, "%s %d\n", name, &k) == 2)
    { // Read name and key from the file
        if (choice == 1)
        {
            loc = lprobe(k); // Use linear probing to find the location
        }
        else if (choice == 2)
        {
            loc = qprobe(k); // Use quadratic probing to find the location
        }
        else
        {
            printf("Invalid choice"); // If invalid choice, exit the program
            fclose(fp);               // Close the file before exiting
            return;
        }
        strcpy(hashTable[loc].name, name); // Store the name in the hash table
        hashTable[loc].key = k;            // Store the key in the hash table
    }

    fclose(fp); // Step 5: Close the file after reading all records

    // Step 6: Display the hash table
    printf("Name\tKey\n"); // Header for the table
    for (i = 0; i < 10; i++)
    {
        printf("%s\t%d\n", hashTable[i].name, hashTable[i].key); // Print each slot
    }
}