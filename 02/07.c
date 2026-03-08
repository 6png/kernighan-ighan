// implement invert(x, p, n) to return x with n->p bits flipped

#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    unsigned mask = ((1 << n) - 1) << (p-n+1);
    return x ^ mask;
}

int main() {
    printf("%x\n", invert(0xFF, 4, 3));
}