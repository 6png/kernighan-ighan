// detab: replace tabs with spaces to next tab stop

#include <stdio.h>

#define TAB         4

int main() {
    int c;
    int len=0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            len=0;
        } else {
            if (c == '\t') {
                for (int i=0; i<TAB-(len%TAB); i++) {
                    putchar(' ');
                    ++len;
                }
            } else {
                putchar(c);
                ++len;
            }
        }
    }

    if (len != 0) {
        putchar('\n');
    }
}