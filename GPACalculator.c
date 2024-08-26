#include <stdio.h>

int main() {
    float totalScore = 0;
    int totalCredit = 0;
    char c;
    c = getchar();
    while (c != EOF && c != '\n') {
        int credit = c - '0';
        while (c = getchar(), c >= '0' && c <= '9') {
            credit = credit * 10 + c - '0';
        }
        float gradePoints = 0;
        char nxt = getchar();
        if (c == 'A') {
            if (nxt == '+') {
                gradePoints = 4.3;
            } else if (nxt == '-') {
                gradePoints = 3.7;
            } else {
                gradePoints = 4.0;
            }
        } else if (c == 'B') {
            if (nxt == '+') {
                gradePoints = 3.3;
            } else if (nxt == '-') {
                gradePoints = 2.7;
            } else {
                gradePoints = 3.0;
            }
        } else if (c == 'C') {
            if (nxt == '+') {
                gradePoints = 2.3;
            } else if (nxt == '-') {
                gradePoints = 1.7;
            } else {
                gradePoints = 2.0;
            }
        } else if (c == 'F') {
            gradePoints = 0;
        }
        totalScore += credit * gradePoints;
        totalCredit += credit;
        if (nxt == EOF || nxt == '\n') break;
        int needBreak = 0;
        if (nxt == '+' || nxt == '-') {
            nxt = getchar();
        }
        if (nxt == EOF || nxt == '\n') break;
        c = nxt;
    }
    printf("%.2f\n", (float)totalScore / totalCredit);
    return 0;
}