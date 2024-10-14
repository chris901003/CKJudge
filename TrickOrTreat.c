#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?a:b)
int array[1500];

int maxChandy(int size) {
    int a = 0, b = 0;
    for (int i = 0; i < size; i++) {
        int take = b + array[i];
        int skip = max(a, b);
        a = take;
        b = skip;
    }
    return max(a, b);
}

int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy( size));
    return 0;
}