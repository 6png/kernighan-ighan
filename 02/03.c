// implement htoi(s) which takes string of hexadecimal digits to int
    // allowable input: 0-9, a-f, A-F

#include <stdio.h>

#define BASE    16

int htoi(char s[], int n) {
    int res=0;
    int offset=0;

    if (n>2) {
        if (s[0] == '0') {
            if (s[1] == 'x' || s[1] == 'X') {
                offset=2;
            }
        }
    }

    for (int i=offset; i<n; i++) {
        int x=0;
        char c=s[i];
        if (c >= '0' && c <= '9') {
            x = c-'0';
        } else if (c >= 'a' & &c <= 'f') {
            x = c-'a'+10;
        } else if (c >= 'A' && c <= 'F') {
            x = c-'A'+10;
        }
        res = res*BASE+x;
    }
    return res;
}

int main() {
    char fourfivezerofivezero[] = "0xaffa";
    printf("%s: %d\n", fourfivezerofivezero, htoi(fourfivezerofivezero, 6));
}