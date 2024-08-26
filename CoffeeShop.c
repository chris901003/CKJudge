#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= 0 || a > 4) {
        printf("Wait, what?\n");
    } else {
        int total = 0;
        if (a == 1) {
            total = 110 * b;
        } else if (a == 2) {
            total = 150 * b;
        } else if (a == 3) {
            total = 135 * b;
        } else if (a == 4) {
            total = 145 * b;
        }
        printf("The total price is %d dollars!\n", total);
    }
    return 0;
}