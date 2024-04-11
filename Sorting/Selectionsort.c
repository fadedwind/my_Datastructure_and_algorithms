#include <stdio.h>


//通常不稳定 ,Time:O(N^2),Space:O(1)

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // 在剩余的未排序部分中找到最小元素的索引
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 将最小元素与当前位置交换
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("排序后的数组：");
    printArray(arr, n);

    return 0;
}

