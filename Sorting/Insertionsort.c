#include <stdio.h>

//稳定 ,Time:O(N^2),Space:O(1)

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        //可以打印每个步骤以理解算法的细节。
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}