// BFS:广度优先搜索

//采用队列进行辅助

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// 图的邻接矩阵表示
bool graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

// BFS遍历函数
void bfs(int start, int numNodes) {
    // 使用队列来存储待访问的节点
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // 将起始节点加入队列，并设置为已访问
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        // 出队列
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        // 遍历当前节点的邻居节点
        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                // 将未访问的邻居节点加入队列，并设置为已访问
                queue[rear++] = i;
                visited[i] = true;
            }
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

    printf("BFS traversal: ");
    bfs(startNode, numNodes);

    return 0;
}