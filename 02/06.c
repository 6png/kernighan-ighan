// implement setbits(x, p, n, y) to replace x's p->n bits with y's n->0 bits

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = (1 << n) - 1;
    int shft = p-n+1;
    y = (y & mask) << shft;
    x = x & ~(mask << shft);
    return x | y;
}

int main() {
    printf("%x\n", setbits(0xFF, 4, 3, 0x02));
}