#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int edgesCnt[101];
int adj[101][101];
double value[101];
double newValue[101];
int n;

int next() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j ++) {
            newValue[j] += value[i] / edgesCnt[i] * adj[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(value[i] - newValue[i]) > 1e-30) res++;
        value[i] = newValue[i];
        newValue[i] = 0;
    }
    return res;
    // return diff > 1e-6;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        value[i] = 1.0 / n;
        int num;
        while (scanf("%d", &num)) {
            if (num == -1) break;
            adj[i][num] = 1;
            edgesCnt[i]++;
        }
    }
    while (next());
    for (int i = 0; i < n; i++) {
        printf("%.2lf%% ", value[i] * 100);
    }
    return 0;
}

/*
3.20% 6.40% 8.00% 8.00% 27.20% 11.20% 19.20% 6.40% 5.60% 4.80% 
*/