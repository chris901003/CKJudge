#include <stdio.h>

int main() {
    float three = 1.7320508f;
    float side = 0.0f;
    scanf("%f", &side);
    float area = (three / 4) * (side * side);
    printf("%.3lf\n", area);
    return 0;
}
