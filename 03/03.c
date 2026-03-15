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

int validmatch(char a, char b) {
    return ((isLower(a) && isLower(b) ||
            isUpper(a) && isUpper(b) ||
            isDigit(a) && isDigit(b))
            && a < b);
}

void expand(char s1[], char s2[]) {
    int i=0, j=0;
    while (s1[i] != '\0') {
        if (s1[i+1] == '-'
            && s1[i+2] != '\0'
            && validmatch(s1[i], s1[i+2])) {
            for (char k=s1[i]; k<s1[i+2]; k++) {
                s2[j++] = k;
            }
            i+=2;
        } else {
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "hello a-b a-b-c a-e-z 0-9 ab-c -a a-d dcba";
    char s2[100000];
    expand(s1, s2);
    printf("%s\n%s\n", s1, s2);
}