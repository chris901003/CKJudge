#include <stdio.h>

int main() {
    int a;
    char dir;
    scanf("%d %c", &a, &dir);
    a = ((a % 26) + 26) % 26;
    int dif = dir == 'a' ? 1 : -1;
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') continue;
        if (c >= 'A' && c <= 'Z') {
            int cur = ((((c - 'A') + a) % 26) + 26) % 26;
            printf("%c", cur + 'A');
            a += dif;
        } else if (c >= 'a' && c <= 'z') {
            int cur = ((((c - 'a') + a) % 26) + 26) % 26;
            printf("%c", cur + 'a');
            a += dif;
        } else {
            printf("%c", c);
        }
        a = (a % 26 + 26) % 26;
    }
    printf("\n");
    return 0;
}