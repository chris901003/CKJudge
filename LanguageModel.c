#include <stdio.h>

int main() {
    double pos = 1;
    for (int i = 0; i < 5; i++) {
        double cur;
        scanf("%lf", &cur);
        pos *= cur;
    }
    printf("%.15lf", pos);
    return 0;
}