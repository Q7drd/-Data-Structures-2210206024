#include <stdio.h>

int n, adj[20][20], visited[20];

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, count = 0;
    
    printf("Dugum sayisi: ");
    scanf("%d", &n);

    printf("Matris:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++) visited[i] = 0;

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            printf("Kume %d: ", count);
            dfs(i);
            printf("\n");
        }
    }
    
    printf("Toplam: %d\n", count);
    return 0;
}
