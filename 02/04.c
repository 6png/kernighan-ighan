// implement squeeze(s1, s2) which deletes each character in s1 that matches any character in s2

#include <stdio.h>

// unoptimized ver using code from chapter
/******
void squeeze(char s1[], char s2[]) {
    int i, j;

    for (i=j=0; s1[i] != '\0'; i++) {
        int k;
        for (k=0; s2[k] != '\0' && s1[i] != s2[k]; k++);
        if (s2[k] == '\0') {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
******/

void prt(char s1[], char s2[]) {
    printf("%s\n", s1);
    printf("%s\n", s2);
}

void squeeze(char s1[], char s2[]) {
    int charmap[256] = {0};
    for (int i=0; s2[i] != '\0'; i++) {
        charmap[(unsigned int)s2[i]] = 1;
    }

    int j=0;
    for (int i=0; s1[i] != '\0'; i++) {
        if (charmap[(unsigned int)s1[i]] == 0) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "abcdefghijk";
    char s2[] = "agiagi";
    prt(s1, s2);
    squeeze(s1, s2);
    prt(s1, s2);
}
