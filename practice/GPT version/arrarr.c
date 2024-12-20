#include <stdio.h>
int arr[100], n, i;

void create() {
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
}

void display() {
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
}

void insert(int elem, int pos) {
    for (i = n++; i >= pos; i--) arr[i] = arr[i - 1];
    arr[pos] = elem;
}

void delete(int pos) {
    for (i = pos; i < n--; i++) arr[i] = arr[i + 1];
}

int main() {
    int choice, elem, pos;
    printf("Enter number of elements: "); scanf("%d", &n);

    while (1) {
        printf("\nMenu: 1.Create 2.Display 3.Insert 4.Delete 5.Exit\n");
        printf("Enter choice: "); scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: printf("Enter element and position: "); scanf("%d %d", &elem, &pos); insert(elem, pos); break;
            case 4: printf("Enter position: "); scanf("%d", &pos); delete(pos); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}