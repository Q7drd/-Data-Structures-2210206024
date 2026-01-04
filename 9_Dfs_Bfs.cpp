#include <stdio.h>

int n, adj[20][20], visited[20];
int queue[20], front = 0, rear = -1;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) dfs(i);
    }
}

void bfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j;
    printf("Dugum sayisi: ");
    scanf("%d", &n);

    printf("Matris:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    dfs(0);

    printf("\nBFS: ");
    bfs(0);

    return 0;
}
