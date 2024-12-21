#include <stdio.h>

// Swap two elements using pointers.
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to maintain the max-heap property at a given node `i`.
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;       // Assume the largest is the root node.
    int left = 2 * i + 1;  // Left child index.
    int right = 2 * i + 2; // Right child index.

    // Check if the left child exists and is greater than the root.
    if (left < n && arr[left] > arr[largest])
    {
        largest = left; // Update the largest to be the left child.
    }

    // Check if the right child exists and is greater than the largest so far.
    if (right < n && arr[right] > arr[largest])
    {
        largest = right; // Update the largest to be the right child.
    }

    // If the largest is not the root, swap them and recursively heapify the affected subtree.
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]); // Swap the current node with the largest child.
        maxHeapify(arr, n, largest);  // Recursively heapify the subtree.
    }
}

// Function to maintain the min-heap property at a given node `i`.
void minHeapify(int arr[], int n, int i)
{
    int smallest = i;      // Assume the smallest is the root node.
    int left = 2 * i + 1;  // Left child index.
    int right = 2 * i + 2; // Right child index.

    // Check if the left child exists and is smaller than the root.
    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left; // Update the smallest to be the left child.
    }

    // Check if the right child exists and is smaller than the smallest so far.
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right; // Update the smallest to be the right child.
    }

    // If the smallest is not the root, swap them and recursively heapify the affected subtree.
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]); // Swap the current node with the smallest child.
        minHeapify(arr, n, smallest);  // Recursively heapify the subtree.
    }
}

// Function to build a max-heap from the given array.
void buildMaxHeap(int arr[], int n)
{
    // Start from the last non-leaf node and heapify all the way to the root.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        printf("Heapifying at index %d for Max Heap...\n", i);
        maxHeapify(arr, n, i); // Heapify the node.
    }
}

// Function to build a min-heap from the given array.
void buildMinHeap(int arr[], int n)
{
    // Start from the last non-leaf node and heapify all the way to the root.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        printf("Heapifying at index %d for Min Heap...\n", i);
        minHeapify(arr, n, i); // Heapify the node.
    }
}

// Function to print the array.
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate heap operations.
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};    // Input array.
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array.

    printf("Original Array: ");
    printArray(arr, n); // Print the original array.

    // Build and print the Max Heap.
    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printArray(arr, n);

    // Build and print the Min Heap.
    buildMinHeap(arr, n);
    printf("Min Heap: ");
    printArray(arr, n);

    return 0; // End of the program.
}
