#include <stdio.h>

int main(void) {
    // 𝟕𝐱⁴ - 𝟖𝐱³ - 𝐱² + 𝟔𝐱 - 𝟐𝟐
    double d;
    scanf("%lf", &d);
    d = 7 * d * d * d * d - 8 * d * d * d - d * d + 6 * d - 22;
    printf("%.1f", d);
    return 0;
}