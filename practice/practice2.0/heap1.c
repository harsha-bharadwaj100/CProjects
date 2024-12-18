#include <stdio.h>

int arr[] = {12, 11, 13, 5, 6, 7};
int n = sizeof(arr) / sizeof(arr[0]);

void printArray(int arr[], int n);

void swap(int *x, int *y)
{
    printf("Swapping %d and %d\n", *x, *y);
    int temp = *x;
    *x = *y;
    *y = temp;
    printArray(arr, n);
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Decrementation (i--) NOT (i++) Be careful!!
    {
        printf("heapifying... %d: \n", i);
        maxHeapify(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Decrementation (i--) NOT (i++) Be careful!!
    {
        printf("heapifying... %d: \n", i);
        minHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{

    printf("Original: ");
    printArray(arr, n);
    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    printArray(arr, n);
    buildMinHeap(arr, n);
    printf("Min Heap: ");
    printArray(arr, n);
}