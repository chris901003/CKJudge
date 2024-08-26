#include <stdio.h>

const unsigned long long num1 = 0x38E38E38E38E3800LLU;
const unsigned long long num2 = 0x2AAAAAAAAAAAAAAALLU;
const unsigned long long num3 = 0x1C71C71C71C71C71LLU;
const unsigned long long mod = 0x7CE66C50E2840000LLU;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    unsigned long long aa = num1 * a % mod;
    unsigned long long bb = num2 * b % mod;
    unsigned long long cc = num3 * c % mod;
    unsigned long long ans = (((aa + bb) % mod) + cc) % mod;
    printf("%llu\n", ans);
    return 0;
}