// implement lower(c) to ret lowercase of given char using conditional expression

#include <stdio.h>

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? ('a'+c-'A') : c;
}

int main() {
    char s[] = "ABCabc!@#aBc";
    for (int i=0; s[i] != '\0'; i++) {
        putchar(lower(s[i]));
    }
    putchar('\n');
}