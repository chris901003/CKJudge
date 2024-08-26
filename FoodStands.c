#include <stdio.h>

int main() {
    int mn = 2147483647, mx = -2147483648;
    int cur;
    while(1) {
        scanf("%d", &cur);
        if (cur == -1) {
            break;
        }
        if (cur < mn) {
            mn = cur;
        }
        if (cur > mx) {
            mx = cur;
        }
    }
    printf("%d\n", mx - mn);
    return 0;
}