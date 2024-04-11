#include <stdio.h>
#include <stdlib.h>

// 定义队列节点
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// 定义队列结构
typedef struct {
    QueueNode* front;   // 第一个节点
    QueueNode* rear;    // 最后一个节点
} Queue;

// 初始化队列
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 入队操作
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队操作
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }

    int data = queue->front->data;
    QueueNode* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return data;
}

// 改：更新队列中的元素
void update(Queue* queue, int oldData, int newData) {
    QueueNode* current = queue->front;

    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }

    printf("Error: Element not found in the queue.\n");
}

// 查：查询队列中的元素
int search(Queue* queue, int data) {
    QueueNode* current = queue->front;

    while (current != NULL) {
        if (current->data == data) {
            return 1; // 元素存在于队列中
        }
        current = current->next;
    }

    return 0; // 元素不存在于队列中
}

// 打印队列中的元素
void printQueue(Queue* queue) {
    QueueNode* current = queue->front;

    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue,1);
    enqueue(&queue,2);
    enqueue(&queue,3);

    printQueue(&queue);
    return 0;
}