#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char c[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c[i]);
    }
    int win[n];
    for (int i = 0; i < n; i++) {
        win[i] = i;
    }
    while(n > 1) {
        char judge;
        scanf(" %c", &judge);
        for (int i = 0; i < n; i += 2) {
            // r, p, s
            if (c[win[i]] == c[win[i + 1]]) {
                if (judge == 's') {
                    win[i / 2] = win[i];
                } else {
                    win[i / 2] = win[i + 1];
                }
            } else if (c[win[i]] == 'r' && c[win[i + 1]] == 'p') {
                win[i / 2] = win[i + 1];
            } else if (c[win[i]] == 'r' && c[win[i + 1]] == 's') {
                win[i / 2] = win[i];
            } else if (c[win[i]] == 'p' && c[win[i + 1]] == 'r') {
                win[i / 2] = win[i];
            } else if (c[win[i]] == 'p' && c[win[i + 1]] == 's') {
                win[i / 2] = win[i + 1];
            } else if (c[win[i]] == 's' && c[win[i + 1]] == 'r') {
                win[i / 2] = win[i + 1];
            } else if (c[win[i]] == 's' && c[win[i + 1]] == 'p') {
                win[i / 2] = win[i];
            }
        }
        n /= 2;
    }
    printf("%d", win[0] + 1);
    return 0;
}