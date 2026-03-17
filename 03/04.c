// rewrite itoa to work correctly for largest negative number

#include <stdio.h>
#include <limits.h>

void reverse(char s[]) {
    int n=0;
    while (s[n]) {
        ++n;
    }
    --n;
    for (int i=0; n>i; n--, i++) {
        char tmp = s[n];
        s[n] = s[i];
        s[i] = tmp;
    }
}

void itoa(int n, char s[]) {
    int sign;
    long nn = n;
    if ((sign = n) < 0) {
        nn = -nn;
    }
    int i=0;
    do {
        s[i++] = nn%10 + '0';
    } while ((nn /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[1000];
    itoa(INT_MIN, s);
    printf("%s\n", s);
}