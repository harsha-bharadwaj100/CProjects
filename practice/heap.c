#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[] = {4, 18, 17, 10, 19, 20, 14, 8, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array Before:\n");
    printArray(arr, n);
    buildHeap(arr, n);
    printf("Array After:\n");
    printArray(arr, n);
}