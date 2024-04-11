#include <iostream>
#include <cstdlib>

#include <queue>
#include <stack>

#include "utils.h"

using namespace std;

// preorder
// 借助stack: 根节点入栈->右孩子入栈->左孩子入栈

void preorder_iterative(treeNode *root) {
    if (root == nullptr)
        return;

    stack<treeNode*> nodeStack; //创建一个栈保存节点
    nodeStack.push(root);       //根节点选择

    while (!nodeStack.empty()) {
        treeNode *node = nodeStack.top();   //保存栈顶结点
        printf("%d", node->data);           //访问结点数据
        nodeStack.pop();                    //栈顶结点出栈

        //子节点入栈
        if (node->right) nodeStack.push(node->right);
        if (node->left) nodeStack.push(node->right);
    }
}

void inorder_iterative(treeNode *root) {
    if (root == nullptr)
        return;

    stack<treeNode*> nodeStack; //创建一个栈保存节点
    treeNode *currentNode = root;

    // 当前节点非空，或栈非空迭代处理
    while (currentNode || !nodeStack.empty()) {

            // 当前节点非空，沿着左子树方向入栈
            while (currentNode) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }
        // 此时栈顶节点没有左子树，或已经访问完左子树
        currentNode = nodeStack.top();
        cout << currentNode->data;
        nodeStack.pop();
        currentNode = currentNode->right;

    }
}

void postorder_iterative(treeNode* root) {
    if (root == nullptr)
        return;

    stack<treeNode*> nodeStack;
    treeNode* currentNode = root;
    treeNode* visitedNode = nullptr;

    while (currentNode || !nodeStack.empty()) {
        while (currentNode) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }

        currentNode = nodeStack.top(); //取栈顶元素

        // 检查右子树是否存在，且未被访问过
        if (currentNode->right && currentNode->right != visitedNode) {
            currentNode = currentNode->right;
        } else {// 子数为空或被访问过
            cout << currentNode->data << " ";
            visitedNode = currentNode;
            currentNode = nullptr;
            nodeStack.pop();
        }
    }
}

void level_order(treeNode *root) {
    if (root == nullptr)
        return;

    queue<treeNode*> nodeQueue;
    nodeQueue.push(root);//根节点初始化为队列的头节点

    while (!nodeQueue.empty()) 
    {
        treeNode *node = nodeQueue.front();            //取队头的头节点
        
        cout << node->data;                            //访问节点数据
        if (node->left) nodeQueue.push(node->left);    //左子节点入队
        if (node->right) nodeQueue.push(node->right);  //右子节点入队
        nodeQueue.pop();                               //头节点出队
    } 
}