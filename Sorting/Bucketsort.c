#include <stdio.h>
#include <stdlib.h>

//可能稳定（取决于桶内用的排序算法）,Time:O(N+k),Space:O(N+k)

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// 桶排序函数
void bucketSort(int arr[], int n, int num_buckets) {
    // 创建桶数组
    int **buckets = (int **)malloc(num_buckets * sizeof(int *));
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }
    
    // 将元素分配到桶中
    for (int i = 0; i < n; i++) {
        int index = arr[i] / num_buckets;
        if (buckets[index] == NULL) {
            buckets[index] = malloc(sizeof(int));
            *buckets[index] = arr[i];
        } else {
            int *current = buckets[index];
            while (*current != arr[i] && *current != 0) {
                current++;
            }
            if (*current != arr[i]) {
                *current = arr[i];
            }
        }
    }
    
    // 对每个桶进行插入排序
    for (int i = 0; i < num_buckets; i++) {
        int *bucket = buckets[i];
        int length = 0;
        while (bucket[length] != 0) {
            length++;
        }
        
        // 使用插入排序对桶进行排序
        for (int j = 1; j < length; j++) {
            int key = bucket[j];
            int k = j - 1;
            while (k >= 0 && bucket[k] > key) {
                bucket[k + 1] = bucket[k];
                k--;
            }
            bucket[k + 1] = key;
        }
    }
    
    // 将排序后的元素放回原始数组
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        int *bucket = buckets[i];
        int length = 0;
        while (bucket[length] != 0) {
            arr[index] = bucket[length];
            length++;
            index++;
        }
        free(buckets[i]);
    }
    free(buckets);
}

// 测试桶排序
int main() {
    int arr[] = {23, 8, 15, 12, 6, 42, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：");
    printArray(arr, n);

    bucketSort(arr, n, 5);

    printf("排序后的数组：");
    printArray(arr, n);

    printf("\n");
    return 0;
}