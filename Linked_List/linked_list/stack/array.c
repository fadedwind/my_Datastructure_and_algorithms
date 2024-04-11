#include <stdio.h>
#define MAX_SIZE 100

// 定义栈结构
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 入栈操作
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = data;
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return -1;
    }

    int data = stack->arr[stack->top];
    stack->top--;

    return data;
}

// 获取栈顶元素
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return -1;
    }

    return stack->arr[stack->top];
}

// 打印栈中的元素
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// 主函数
int main() {
    Stack stack;
    initStack(&stack);

    // 使用push函数向栈中添加数字
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // 打印栈中的元素
    printStack(&stack);

    // 出栈操作
    int popped = pop(&stack);
    printf("Popped element: %d\n", popped);

    // 获取栈顶元素
    int topElement = peek(&stack);
    printf("Top element: %d\n", topElement);

    return 0;
}