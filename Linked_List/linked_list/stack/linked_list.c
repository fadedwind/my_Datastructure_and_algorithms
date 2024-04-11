#include <stdio.h>
#include <stdlib.h>

// 栈的链表节点结构
struct StackNode {
    int data;
    struct StackNode* next;
};

// 栈结构
struct Stack {
    struct StackNode* top; // 栈顶
};

// 初始化栈
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// 压栈操作
void push(struct Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 弹栈操作
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        // 栈为空
        printf("Stack is empty.\n");
        return -1;
    }

    // 取出栈顶节点的数据
    int data = stack->top->data;

    // 更新栈顶
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;

    // 释放原栈顶节点的内存
    free(temp);

    return data;
}

int main() {
    // 使用栈
    struct Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60);

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));

    return 0;
}