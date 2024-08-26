#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long prefix = 0;
    while (n--) {
        int cur;
        scanf("%d", &cur);
        prefix += cur;
        if ((prefix % cur) == 0) {
            printf("%lld %d\n", prefix, cur);
        }
    }
    return 0;
}