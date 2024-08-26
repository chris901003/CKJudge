#include <stdio.h>

int main() {
    float height = 0.0f;
    float weight = 0.0f;
    scanf("%f %f", &height, &weight);
    height /= 100;
    float bmi = weight / (height * height);
    printf("%.6f\n", bmi);
    return 0;
}