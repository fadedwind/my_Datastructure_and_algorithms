#include <stdio.h>

#define MAX_SIZE 100

// 定义队列结构
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// 增：入队操作
void enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("队列已满，无法入队\n");
        return;
    }
    queue->data[++queue->rear] = value;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

// 删除队列中的第一个元素：出队操作
int dequeue(Queue *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("队列为空，无法出队\n");
        return -1;
    }
    int value = queue->data[queue->front++];
    if (queue->front > queue->rear) {
        // 队列已为空：
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

// 改：修改队列中指定位置的元素
void modify(Queue *queue, int index, int newValue) {
    if (index < 0 || index > queue->rear) {
        printf("无效的索引\n");
        return;
    }
    queue->data[index] = newValue;
}

// 查：查询队列中指定位置的元素
int search(Queue *queue, int index) {
    if (index < 0 || index > queue->rear) {
        printf("无效的索引\n");
        return -1;
    }
    return queue->data[index];
}

int main() {
    Queue queue;
    initQueue(&queue);
//队列创建完成了

    return 0;
}
