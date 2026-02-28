// entab: replace spaces with min tabs+blanks
    // *prefer space when only 1 needed to next tab stop

#include <stdio.h>

#define TAB_SZ  4

int eqTab(int s[], int n) {
    if (n != TAB_SZ) return -1;
    for (int i=0; i<TAB_SZ; i++) {
        if (s[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int printBuf(int buf[], int n) {
    if (n > TAB_SZ) return -1;
    for (int i=0; i<n; i++) {
        putchar(buf[i]);
    }
    return 0;
}

int main() {
    int c;
    int lineLen=0, bufCt=0;
    int buf[TAB_SZ] = {0};

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printBuf(buf, bufCt);
            putchar('\n');
            lineLen=0;  bufCt=0;
        } else {
            if (bufCt<TAB_SZ) {
                buf[bufCt] = c;
            } else {
                if (eqTab(buf, TAB_SZ) == 1) {
                    putchar('\t');
                } else {
                    printBuf(buf, TAB_SZ);
                }
                bufCt=0;
                lineLen -= TAB_SZ;
                buf[bufCt] = c;
            }
            ++lineLen;  ++bufCt;
        } 
    }

    printBuf(buf, bufCt);

    if (lineLen > 0) {
        putchar('\n');
    }
}