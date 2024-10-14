#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1];
    char name[n+1][18];
    char transfer[18];
    for (int i = 0; i < n + 1; i++) {
        scanf("%d %s", &a[i], name[i]);
        for (int j=0;j<a[i];j++) {
            name[i][j] = tolower(name[i][j]);
        }
    }
    strcpy(transfer, name[0]);
    qsort(name, n + 1, 18, cmp);
    for (int i = 0; i < n + 1; i++) {
        if (strcmp(name[i], transfer) == 0) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}

// 55