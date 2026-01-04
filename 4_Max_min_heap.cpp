#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int main() {
    int data[] = {4, 10, 3, 5, 2};
    int n = 5;

    for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(data, n, i);
    printf("Max Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", data[i]);

    int data2[] = {4, 10, 3, 5, 2};
    for (int i = n / 2 - 1; i >= 0; i--) minHeapify(data2, n, i);
    printf("\nMin Heap: ");
    for (int i = 0; i < n; i++) printf("%d ", data2[i]);

    return 0;
}
