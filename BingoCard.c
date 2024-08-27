#include <stdio.h>

struct Pair {
    int x;
    int y;
};

int main() {
    
    struct Pair records[257];
    for (int i = 0; i < 257; i++) {
        records[i].x = -1;
        records[i].y = -1;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int num;
            scanf("%d", &num);
            records[num].x = i;
            records[num].y = j;
        }
    }
    int visited[8][8] = {0};
    for (int i = 0; i < 64; i++) {
        int num;
        scanf("%d", &num);
        if (records[num].x != -1) {
            visited[records[num].x][records[num].y] = 1;
        }
    }
    int lineCount = 0;
    for (int i = 0; i < 8; i++) {
        int line = 1;
        for (int j = 0; j < 8; j++) {
            if (!visited[i][j]) {
                line = 0;
                break;
            }
        }
        lineCount += line;
    }
    for (int i = 0; i < 8; i++) {
        int line = 1;
        for (int j = 0; j < 8; j++) {
            if (!visited[j][i]) {
                line = 0;
                break;
            }
        }
        lineCount += line;
    }
    int line = 1;
    for (int i = 0; i < 8; i++) {
        if (!visited[i][i]) {
            line = 0;
            break;
        }
    }
    lineCount += line;
    line = 1;
    for (int i = 0; i < 8; i++) {
        if (!visited[i][7 - i]) {
            line = 0;
            break;
        }
    }
    lineCount += line;
    printf("%d\n", lineCount);
    
    return 0;
}