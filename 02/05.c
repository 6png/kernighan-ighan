// implement any(s1, s2) to ret earliest pos of any s2 char found in s1
// ret -1 if none found

#include <stdio.h>

int any(char s1[], char s2[]) {
    /* unoptimized
        for (int i=0; s1[i] != '\0'; i++) {
        for (int j=0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
    */

    int charmap[256] = {0};
    for (int i=0; s2[i] != '\0'; i++) {
        charmap[(unsigned int)s2[i]] = 1;
    }

    int j=0;
    for (int i=0; s1[i] != '\0'; i++) {
        if (charmap[(unsigned int)s1[i]] != 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char s1[] = "abcdefghijk";
    char s2[] = "pqrstk";
    printf("%d\n", any(s1, s2));
}