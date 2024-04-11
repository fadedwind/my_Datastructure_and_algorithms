#include <stdio.h>

//不稳定 ,Time:O(N*logN),Space:O(1)

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(&arr[root],&arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Perform sorting
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

}