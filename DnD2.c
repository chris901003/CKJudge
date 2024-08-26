#include <stdio.h>

int main() {
    int player = 100, dragon = 100;
    int a, b, c, d, e, f;
    while (1) {
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        if ((a + b + c) % 2) {
            // Player
            int d1 = d % 2;
            int e1 = e % 2;
            int f1 = f % 2;
            if (d < e && e < f) {
                dragon -= 25;
            } else if (d1 == e1 || e1 == f1) {
                dragon -= 5;
            }
        } else {
            // Dragon
            if (d - e > f || e - d > f) {
                player -= 15;
            } else if ((d + e) != f) {
                player -= 5;
            }
        }
        if (player <= 0) {
            printf("Dragon wins");
            break;
        } else if (dragon <= 0) {
            printf("Player wins");
            break;
        }
    }
    return 0;
}