#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int isFirst = 1;
    int cnt;
    scanf("%d\n", &cnt);
    while (cnt) {
        char cur = getchar();
        if (cur == ',' || cur == ';' || cur == '.') {
            isFirst = 1;
            cnt -= 1;
            printf("\n");
        } else {
            if (isFirst) {
                printf("%c", toupper(cur));
                isFirst = 0;
            } else {
                printf("%c", tolower(cur));
                if (cur == ' ') isFirst = 1;
            }
        }
    }
    return 0;
}