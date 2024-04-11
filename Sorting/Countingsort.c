#include <stdio.h>
#include <stdlib.h>

//仅适用于较小的数组
//稳定 ,Time:O(N+k),Space:O(k)

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 计数排序函数
void countingSort(int arr[], int n) {
    // 找出待排序数组中的最大值
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 创建计数数组并初始化为0
    int* count = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // 统计每个元素出现的次数
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 对计数数组进行累加操作
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 创建临时数组并
    int* output = (int*)malloc(n * sizeof(int));
    
    // 将元素放置到正确的位置上
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 将临时数组的元素复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // 释放动态分配的内存
    free(count);
    free(output);
}

// 测试计数排序算法
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：");
    printArray(arr, n);

    countingSort(arr, n);

    printf("排序后数组：");
    printArray(arr, n);

    return 0;
}