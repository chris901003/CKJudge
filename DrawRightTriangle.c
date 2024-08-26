#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int mid = 0;
    int dif = 1;
    int isStarFront = 0;
    if (a == 1) {
        mid = b;
        isStarFront = 1;
        dif = -1;
    } else if (a == 2) {
        mid = 1;
        isStarFront = 1;
    } else if (a == 3) {
        mid = 0;
    } else if (a == 4) {
        mid = b - 1;
        dif = -1;
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            if (isStarFront) {
                if (j < mid) printf("*");
                else printf(" ");
            } else {
                if (j < mid) printf(" ");
                else printf("*");
            }
        }
        printf("\n");
        mid += dif;
    }
    return 0;
}