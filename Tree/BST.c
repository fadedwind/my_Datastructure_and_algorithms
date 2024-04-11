#include <stdio.h>
#include <stdlib.h>

//binary searchNode tree： 二叉搜索树
//可在O(logN)时间复杂度查找一个数是否存在

// 左子树的所有节点都小于根节点
// 右子树的所有结点都大于根节点
// 每个节点的左右子树也是BST

typedef struct treeNode
{
    int data;                // 数据
    struct treeNode *left;   // 左子节点
    struct treeNode *right;  // 右子节点
} treeNode;

treeNode* newNode(int data)
{
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

treeNode* minValueNode(treeNode* root) {
    // 找到最左边的叶节点
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

treeNode* maxValueNode(treeNode* root) {
    // 找到最右边的叶节点
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// BST:插入
treeNode* insertNode(treeNode* root, int key) {

    //根节点为空或根节点的值为要查找的值
    if (!root)
        return newNode(key);

    // 要查找的值小于根节点的值，则插入到左子树
    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else {//否则，插入到右子树
        root->right = insertNode(root->right, key);
    }

    // 插入后返回当前根节点
    return root;
}

// BST：删除
//1）要删除的节点是叶节点          ---直接删除
//2) 要删除的节点只有一个子节点    ---用子节点替换，再删除字节点

//3) 要删除的节点有两个子节点      ---最复杂
//{ 找到要删除节点x中序遍历的后继节点y(也可以用前驱节点）； 将节点y的值复制给x； 删除节点y；}


treeNode* deleteNode(treeNode* root, int key){
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data) 
        root->right = deleteNode(root->right, key);
    else{
        if (root->left == NULL) {
            treeNode* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            treeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 两个子节点：查找中序遍历后继(右子树最小值)
        treeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
}


// BST：查找
treeNode* searchNode (treeNode* root, int key) {

    //根节点为空或根节点的值为要查找的值
    if (root == NULL || root->data == key)
        return root;

    // 要查找的值小于根节点的值
    if (key < root->data) {
        return searchNode(root->left, key);
    } else  { // 要查找的值大于根节点的值
        return searchNode(root->right, key);
    }
}
