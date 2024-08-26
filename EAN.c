#include <stdio.h>

int main() {
    char ean[13];
    scanf("%12s", ean);
    int a = 0, b = 0;
    for (int i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            b += ean[i] - '0';
        } else {
            a += ean[i] - '0';
        }
    }
    int x = a * 3 + b;
    int y = x - 1;
    int z = y % 10;
    int res = 9 - z;
    printf("%d\n", res);
    return 0;
}