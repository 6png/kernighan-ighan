// entab: replace spaces with min tabs+blanks
    // *prefer space when only 1 needed to next tab stop

#include <stdio.h>

#define TAB_SZ  4

int main() {
    int c;
    int len=0, cCt=0;
    int buf[TAB_SZ] = {0};

    while ((c = getchar()) != EOF) {
        if (cCt<TAB_SZ) {
            ++len;  ++cCt;
            buf[cCt] = c;
        } else {

        }
    }
}

int eqTab(int s[]) {
    if ()
}