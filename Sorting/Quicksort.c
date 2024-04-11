#include <stdio.h>

//不稳定 ,Time:O(N*logN),Space:O(logN)

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

//分治的思想
int partition(int arr[], int low, int high) {

    //基准：pivot
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <high; j++) {

        //比pivot小的，都换到前面去
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int arr[20];
    int n;

    printf("Enter the number of elements (up to 20): ");
    scanf("%d", &n);


    printf("Enter the elements: ");
    printf("\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Initial array: ");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}