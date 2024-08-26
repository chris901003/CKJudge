#include <stdio.h>

int main() {
    char c[9];
    scanf("%s", c);
    int cur = 0;
    for (int i = 0; i < 8; i++) {
        cur *= 16;
        if (c[i] >= '0' && c[i] <= '9') {
            cur += c[i] - '0';
        } else {
            cur += c[i] - 'a' + 10;
        }
        if (i % 2) {
            printf("%d", cur);
            if (i != 7) printf(".");
            cur = 0;
        }
    }
    return 0;
}