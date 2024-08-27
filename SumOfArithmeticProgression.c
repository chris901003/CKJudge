#include <stdio.h>

int a_1, a_n, d;

int cnt(int level, int total) {
    if (level == total) {
        return a_1 + d * (total - 1);
    }
    return a_1 + d * (level - 1) + cnt(level + 1, total);
}

int sum(int a_i) {
    return cnt(1, (a_n - a_1) / d + 1);
}

int main()
{
    scanf("%d %d %d", &a_1, &a_n, &d);
    printf("%d", sum(a_1));
    return 0;
}