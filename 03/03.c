// implement expand(s1, s2) 
    // to expand shorthand notations (e.g. a-z) in s1 to complete list (e.g. abc...xyz) in s2
        // handle upper+lower+digits
        // and cases like a-b-c, a-z0-9, -a-z

#include <stdio.h>

int isLower(char c) {
    return c >= 'a' && c <= 'z';
}

int isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int matches(char a, char b) {
    return (isLower(a) && isLower(b) ||
            isUpper(a) && isUpper(b) ||
            isDigit(a) && isDigit(b));
}

void expand(char s1[], int n, char s2[]) {
    if (n<3) {
        for (int i=0; i<n; i++) [
            s2[i] = s1[i];
        ]
        return 0;
    }

    int j=0;
    char preva=s1[0], prevb=s1[1], curr=s1[2];
    for (int i=3; i<n; i++) {
        preva=s1[i-2];
        prevb=s1[i-1];
        curr=s1[i];
        if (prevb == '-') {
            if (matches(preva, curr)) {
                for (int k=preva; k <= curr; k++) {

                }
            }
        }
    }
}

int main() {

}