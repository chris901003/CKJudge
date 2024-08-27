#include <stdio.h>

int main() {
    int disc[7];
    for (int i = 0; i < 8; i++) disc[i] = 0;
    for (int i = 0; i < 75; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        disc[a] = (disc[a] + (b % 2 ? 1 : -1) + 10) % 10;
    }
    for (int i = 1; i <= 6; i++) {
        printf("%d ", disc[i]);
    }
    return 0;
}