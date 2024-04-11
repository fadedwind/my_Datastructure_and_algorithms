#include <stdio.h>

//不稳定 ,Time:O(N^2),Space:O(1)

// increments 5，2，1
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shellSort(int arr[], int n) {

    int inc, i, j, key;

    for(inc = n / 2; inc > 0; inc /= 2) {

        //每一趟进行插入排序  e.g. : 5-排序， 3-排序  ,1-排序
        for (i = inc; i < n; i++) {
            key = arr[i];
            for (j = i; j >= inc && key < arr[j-inc]; j -= inc) {
                arr[j] = arr[j - inc];
            }
            arr[j] = key;
        }            
    }
}

int main() {
    int arr[] = {12, 2, 16, 30, 28, 10, 16, 20, 6, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array: ");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}