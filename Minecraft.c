#include <stdio.h>

int n;
int make[21][21];
int res;

int making(int target) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (make[target][i]) cnt += making(i);
    }
    return cnt == 0 ? 1 : cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 1; j <= n; j++) {
            make[i][j] = 0;
        }
        for (int j = 0; j < m; j++) {
            int a;
            scanf("%d", &a);
            make[i][a] = 1;
        }
    }
    res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = making(i);
        res += cnt;
    }
    printf("%d\n", res);
    return 0;
}