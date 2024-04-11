#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 定义链表节点
typedef struct Node {
    ElementType data;
    struct Node* next;
}Node;

// 链表结构
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

//初始化链表
Node* initList() {
    return NULL;
}

// 创建一个空链表
LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// 检查链表是否为空
int isEmpty(LinkedList* list) {
    return list->size == 0;
}

// 返回链表的大小
int size(LinkedList* list) {
    return list->size;
}

//向链表开头添加一个新节点
Node* insert_at_beginning(Node* head, ElementType data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    return newNode;
}

// 向链表末尾添加一个新节点
Node* insert_at_end(Node* head, ElementType data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return newNode;
}

// 在指定位置插入节点
Node* insert(Node* head, ElementType data, int pos) {
    if (pos < 0) {
        printf("Error: Invalid position.\n");
        return head;
    }

    if (pos == 0) {
        return insert_at_beginning(head, data);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* current = head;
    int count = 0;

    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Error: Invalid position.\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// 删除链表中的节点
Node* deleteNode(Node* head, ElementType data) {

    if (head == NULL) {
        printf("Error: List is empty.\n");
        return NULL;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Error: Element not found in the list.\n");
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

// 打印链表中的元素
void printList(Node* head) {
    Node* current = head;

    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = initList();

    // 在链表开头插入节点
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 0);

    // 在链表末尾插入节点
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);

    // 在指定位置插入节点
    head = insert(head, 4, 2);

    // 删除节点
    head = deleteNode(head, 2);

    // 打印链表中的元素
    printList(head);

    return 0;
}