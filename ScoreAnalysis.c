#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int scores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int lower, upper;
        scanf("%d %d", &lower, &upper);
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (scores[i] < lower) {
                a += 1;
            } else if (scores[i] >= upper) {
                c += 1;
            } else {
                b += 1;
            }
        }
        printf("%d %d %d\n", a, b, c);
    }
}