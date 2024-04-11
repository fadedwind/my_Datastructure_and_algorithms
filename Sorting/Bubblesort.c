#include <stdio.h>

//稳定 ,Time:O(N^2),Space:O(1)

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

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // 每次遍历将最大的元素冒泡到末尾
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换相邻的两个元素
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组：");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("排序后的数组：");
    printArray(arr, n);

    return 0;
}