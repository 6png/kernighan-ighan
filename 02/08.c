// implement rightrot(x, n)

#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n) {
    int ubits = sizeof(unsigned) * CHAR_BIT;
    unsigned xx = x << (ubits-n);
    x = x >> n;
    return xx | x;
}

int main() {
    printf("%x\n", rightrot(0xFF, 4));
}