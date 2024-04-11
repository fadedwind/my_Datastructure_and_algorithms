#include <stdio.h>
#include <stdlib.h>

// AVL树是对BST的改进
// 自平衡的二叉树

// 平衡因子p = Height(TL)-Height(TR)
// 若每个节点的平衡因子的绝对值都<=1,则这棵树是AVL树

typedef struct treeNode
{
    int key;                // 数据
    struct treeNode *left;   // 左子节点
    struct treeNode *right;  // 右子节点
    int height;
} treeNode;

// 辅助函数：比大小
int Max(int a, int b) {
    return a > b ? a : b;
}

// 辅助函数：计算树的高度
int height(treeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + Max(height(root->left), height(root->right));
}

// 辅助函数：创建新节点
treeNode* newNode(int key)
{
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 辅助函数：获得节点的平衡因子
int getBalanceFactor(treeNode *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// AVL:插入
// ->1.首先在叶节点插入数据
// ->2.若插入导致不平衡，需对插入路径上距离插入节点最近的
//   平衡因子绝对值大于一的节点为根的树进行调整

//{ 
//  LL型 ：右单旋转
//  RR型 ：左单旋转 
//  LR型 ：左右双旋
//  RL型 ：右左双旋
//       }

// 右旋
treeNode *rightRotate(treeNode *y)
{
    /* 树结构示意图：
                y
               / \
              x   O
             / \
            O   O
    */
    treeNode *x = y->left;
    treeNode *xr = x->right;
    // 旋转
    x->right = y;
    y->left = xr;
    // 更新节点的高度
    x->height = height(x);
    y->height = height(y);
    // 返回旋转后的根节点
    return x;
}

// 左旋
treeNode *leftRotate(treeNode *y)
{
    /* 树结构示意图：
                y
               / \
              O   x
                 / \
                O   O
    */
    treeNode *x = y->right;
    treeNode *xl = x->left;
    // 旋转
    x->left = y;
    y->right = xl;
    // 更新节点的高度
    x->height = height(x);
    y->height = height(y);
    // 返回旋转后的根节点
    return x;
}

/**
 * @brief 向以node为根节点的树中插入key
 *
 * @param node 根节点
 * @param key 插入值
 * @return treeNode* 插入后该树的新的根节点
 */

treeNode *insert(treeNode *node, int key)
{
    // 1. 按照BST的方法在叶节点上插入新值
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // 值已经存在

    // 2. 更新插入路径上每棵子树的高度
    node->height = height(node);

    // 3. 计算平衡因子，不平衡则需要调整
    int bf = getBalanceFactor(node);

    // LL型不平衡
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);
    // RR型不平衡
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);
    // LR型不平衡
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL型不平衡
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // 如果是平衡的直接返回根节点
    return node;
}

// 辅助函数：输出树的先序遍历
void preOrder(treeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    struct treeNode *root = NULL;

    /* 测试，最终树结构应该如下图所示：
            30
           /  \
         20   40
        /  \     \
       10  25    50
    */

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf(
        "Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);
    putchar('\n');

    return 0;
}

