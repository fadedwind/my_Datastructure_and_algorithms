#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct Heap {
    int array[MAX_SIZE];
    int size;
} Heap;

// 初始化堆的函数
Heap* initialize() {
    Heap* h = (Heap*)malloc(sizeof(Heap)); // 填空1：创建并返回一个新的堆
    h->size = 0;
    return h;
}

// 向堆中插入元素的函数
void insert(Heap* h, int key) {
    if (h->size == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    h->size++;
    int i = h->size - 1;
    h->array[i] = key;

    // 向上调整堆
    while (i != 0 && h->array[(i - 1) / 2] > h->array[i]) {
        // 交换当前节点和父节点
        int temp = h->array[i];
        h->array[i] = h->array[(i - 1) / 2];
        h->array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// 从堆中删除最小元素的函数
int deleteMin(Heap* h) {
    if (h->size <= 0) return INT_MAX;
    if (h->size == 1) {
        h->size--;
        return h->array[0];
    }
    int root = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    // 向下调整堆
    int index = 0;
    while (index < h->size) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < h->size && h->array[left] < h->array[smallest])
            smallest = left;

        if (right < h->size && h->array[right] < h->array[smallest])
            smallest = right;

        if (smallest != index) {
            // 交换当前节点和最小的子节点
            int temp = h->array[index];
            h->array[index] = h->array[smallest];
            h->array[smallest] = temp;

            index = smallest;
        } else {break;}
    }
    return root;
}

// 主函数
int main() {
    Heap* heap = initialize();
    insert(heap, 1); // 填空3：插入元素到堆中

    printf("删除最小元素：%d\n", deleteMin(heap));
}
