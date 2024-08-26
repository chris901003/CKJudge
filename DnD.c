#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    int turn = a + b + c;
    int isPlayer = 0;
    if (turn <= 10) {
        printf("Player attacks: ");
        isPlayer = 1;
    } else {
        printf("Dragon attacks: ");
    }
    if (isPlayer) {
        if (d == e && e == f) {
            printf("Critical Hit\n");
        } else if (d + e >= f) {
            printf("Normal Hit\n");
        } else {
            printf("Miss\n");
        }
    } else {
        if (d == e || e == f || d == f) {
            printf("Miss\n");
        } else if (d + e != f) {
            printf("Normal Hit\n");
        } else {
            printf("Critical Hit\n");
        }
    }
    return 0;
}