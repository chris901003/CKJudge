#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
    if (k == 0) {
        *f2k = 1;
        *f2k1 = 1;
        return;
    }
    uint64_t f_k, f_k1;
    fib_fast_doubling(k / 2, &f_k, &f_k1);
    *f2k = f_k * (2 * f_k1 - f_k);
    *f2k1 = f_k * f_k + f_k1 * f_k1;
    return;
}

int main()
{
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}