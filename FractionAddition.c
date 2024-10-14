#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void fraction_adder(
    int a_numerator, 
    int a_denominator, 
    int b_numerator,
    int b_denominator, 
    int *c_numerator_ptr, 
    int *c_denominator_ptr
    ) {
    *c_numerator_ptr = a_numerator * b_denominator + b_numerator * a_denominator;
    *c_denominator_ptr = a_denominator * b_denominator;
    int g = gcd(*c_numerator_ptr, *c_denominator_ptr);
    *c_numerator_ptr /= g;
    *c_denominator_ptr /= g;
    }

int main() {
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
           &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}