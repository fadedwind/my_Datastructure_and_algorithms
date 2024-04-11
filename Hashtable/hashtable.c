#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// 定义哈希表节点结构
struct Node {
    int key;
    int value;
    struct Node* next;
};

// 哈希表结构
struct HashTable {
    struct Node* array[SIZE];
};

// 创建哈希表
struct HashTable* createHashTable() {
    struct HashTable* hashtable = (struct HashTable*)malloc(sizeof(struct HashTable));
    memset(hashtable, 0, sizeof(struct HashTable));
    return hashtable;
}

// 哈希函数
int hashFunction(int key) {
    return key % SIZE;
}

// 插入键值对
void insert(struct HashTable* hashtable, int key, int value) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashtable->array[index] == NULL) {
        hashtable->array[index] = newNode;
    } else {
        struct Node* current = hashtable->array[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 查找键对应的值
int lookup(struct HashTable* hashtable, int key) {
    int index = hashFunction(key);
    struct Node* current = hashtable->array[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // 未找到对应的键
}

// 删除键值对
void delete(struct HashTable* hashtable, int key) {
    int index = hashFunction(key);
    struct Node* current = hashtable->array[index];
    struct Node* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hashtable->array[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// 打印哈希表
void printHashTable(struct HashTable* hashtable) {
    
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* current = hashtable->array[i];
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// 主函数
int main() {
    struct HashTable* hashtable = createHashTable();

    insert(hashtable, 5, 10);
    insert(hashtable, 15, 20);
    insert(hashtable, 25, 30);
    insert(hashtable, 35, 40);

    printf("Hashtable:\n");
    printHashTable(hashtable);

    printf("Value for key 15: %d\n", lookup(hashtable, 15));
    printf("Value for key 35: %d\n", lookup(hashtable, 35));

    delete(hashtable, 15);
    delete(hashtable, 25);

    printf("Hashtable after deletion:\n");
    printHashTable(hashtable);

    return 0;