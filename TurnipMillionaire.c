#include <stdio.h>

int main() {
    float price = 0.0;
    scanf("%f", &price);

    float w = 0.9;
    float u = 0.1;
    float b = -51;
    float up = -0.98;
    float bp = 153;

    // h{t+1} = w * x{t} + u * h{t} + b
    // y{t+1} = u' * h{t+1} + b'
    // h[0] = 0

    float hs[6];
    float xs[6];
    float ys[6];
    hs[0] = 0;
    xs[0] = price;
    for (int i = 1; i <= 5; i++) {
        hs[i] = w * xs[i - 1] + u * hs[i - 1] + b;
        ys[i] = up * hs[i] + bp;
        xs[i] = ys[i];
        printf("%.1f ", ys[i]);
    }
    return 0;
}