//堆是一种满足堆属性的完全二叉树。

// 完全二叉树（complete tree）
// 完全二叉树是一种特殊的二叉树，其中除了最后一层可能不满外，其他层的节点都是满的，并且最后一层的节点都尽可能地靠左排列。
// 完全二叉树通常使用数组来表示，其中每个节点在数组中的索引位置与二叉树的层次遍历顺序相对应。

// 堆属性
// 在堆中，每个节点都满足堆属性，具体取决于是最大堆（Max Heap）还是最小堆（Min Heap）：

// 最大堆：对于每个节点x，x的值大于或等于其子节点的值。换句话说，堆中的最大元素位于根节点。
// 最小堆：对于每个节点x，x的值小于或等于其子节点的值。换句话说，堆中的最小元素位于根节点。

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int* heapArray;
    int capacity;
    int size;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->heapArray = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

void destroyHeap(Heap* heap) {
    free(heap->heapArray);
    free(heap);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap* heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->heapArray[index] > heap->heapArray[parent]) {
        swap(&heap->heapArray[index], &heap->heapArray[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(Heap* heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap->size && heap->heapArray[leftChild] > heap->heapArray[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap->size && heap->heapArray[rightChild] > heap->heapArray[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap->heapArray[index], &heap->heapArray[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(Heap* heap, int value) {
    if (heap->size < heap->capacity) {
        heap->heapArray[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
    }
}

int removeMax(Heap* heap) {
    if (heap->size > 0) {
        int max = heap->heapArray[0];
        heap->heapArray[0] = heap->heapArray[heap->size - 1];
        heapifyDown(heap, 0);
        heap->size--;
        return max;
    }
    return -1;
}

void printHeap(Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->heapArray[i]);
    }
    printf("\n");
}

int main() {
    Heap* heap = createHeap(MAX_HEAP_SIZE);

    insert(heap, 10);
    insert(heap, 30);
    insert(heap, 20);
    insert(heap, 50);
    insert(heap, 40);

    printf("Initial ");
    printHeap(heap);

    int max = removeMax(heap);
    printf("Removed max element: %d\n", max);

    printf("Updated ");
    printHeap(heap);

    destroyHeap(heap);

    return 0;
}