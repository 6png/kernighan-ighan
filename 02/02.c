// write loop equiv to the below without using && and ||
/*
    int i;
    char c;
    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
*/

#include <stdio.h>

int main() {
    int i;
    char c;
    int lim = 10;
    int s[lim];
    for (i=0; i<lim-1; ++i) {
        c = getchar();
        if (c == EOF) {
            return 0;
        } else if (c == '\n') {
            return 0;
        } else {
            s[i] = c;
        }
    }
}