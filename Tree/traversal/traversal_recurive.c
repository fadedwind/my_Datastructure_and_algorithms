#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// 前序遍历（根-左-右）
void preorder_recursive(treeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

// 中序遍历（左-根-右）
void inorder_recursive(treeNode* root) {
    if (root == NULL)
        return;
    inorder_recursive(root->left);
    printf("%d ", root->data);
    inorder_recursive(root->right);
}

// 后序遍历（左-右-根）
void postorder_recursive(treeNode* root) {
    if (root == NULL)
        return;
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    printf("%d ", root->data);
}

void test(){
    // 由数组创建二叉树
    int arr[] = {1,2,3,-1,4,5,6,-1,-1,7};
    int n = NELEMS(arr);
    treeNode *root = createTreeFromArray(arr,n);

    printf("Preorder _recursive: ");
    preorder_recursive(root);
    printf("\n");

    printf("Inorder _recursive: ");
    inorder_recursive(root);
    printf("\n");

    printf("Postorder _recursive: ");
    postorder_recursive(root);
    printf("\n");
}

// 测试二叉树遍历
int main() {
    test();
    return 0;
}