// DFS:深度优先搜索

//采用栈进行辅助

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// 图的邻接矩阵表示
bool graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

// DFS遍历函数
void dfs(int currentNode, int numNodes) {
    printf("%d ", currentNode);
    visited[currentNode] = true;

    // 遍历当前节点的邻居节点
    for (int i = 0; i < numNodes; i++) {
        if (graph[currentNode][i] && !visited[i]) {
            // 递归调用DFS函数遍历未访问的邻居节点
            dfs(i, numNodes);
        }
    }
}

int main() {
    int numNodes, numEdges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &numNodes, &numEdges);

    // 初始化图的邻接矩阵和访问数组
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = false;
        }
        visited[i] = false;
    }

    printf("Enter the edges (node1 node2): \n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        // 在邻接矩阵中标记边的存在
        graph[node1][node2] = true;
        graph[node2][node1] = true;
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    printf("DFS traversal: ");
    dfs(startNode, numNodes);

    return 0;
}