#include <stdio.h>

int adj[101][101];
int related[101][101];

void dfs(int cur, int root) {
    for (int i = 1; i <= 100; i++) {
        if (adj[cur][i] == 1 && related[root][i] == 0) {
            related[root][i] = 1;
            dfs(i, root);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (1) {
        int num;
        scanf("%d", &num);
        if (num == 0) break;
        char buffer[300];
        fgets(buffer, 300, stdin);
        int idx = 0;
        while (buffer[idx] != '\0' && buffer[idx] != '\n') {
            if (buffer[idx] == ' ') {
                idx++;
                continue;
            }
            int cur = 0;
            while (buffer[idx] != ' ' && buffer[idx] != '\0' && buffer[idx] != '\n') {
                cur = cur * 10 + buffer[idx] - '0';
                idx++;
            }
            adj[num][cur] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        related[i][i] = 1;
        dfs(i, i);
        printf("%d -> ", i);
        for (int j = 1; j <= n; j++) {
            if (related[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}

/*
1 -> 1 2 4
2 -> 2 4
3 -> 3 4
4 -> 4
5 -> 1 2 3 4 5
*/