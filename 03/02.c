// implement escape(s, t) to convert whitespace to visible escape sequences while copying t to s and using switch statement
// implement unescape(s, t) to do the opposite

#include <stdio.h>

void escape(char s[], char t[]) {
    int i=0;
    for (int j=0; t[j] != '\0'; j++) {
        switch(t[j]) {
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                break;
            default:
                s[i++] = t[j];
        }
    }
    s[i] = '\0';
}

void unescape(char s[], char t[]) {
    int i=0, j=0;
    while (t[j] != '\0') {
        if (t[j] == '\\') {
            switch(t[j+1]) {
                case 'n':
                    s[i++] = '\n';
                    j+=2;
                    break;
                case 't':
                    s[i++] = '\t';
                    j+=2;
                    break;
                default:
                    s[i++] = t[j++];
            }
        } else {
            s[i++] = t[j++];
        }
    }
    s[i] = '\0';
}

int main() {
    char t[] = "a string without escape sequences\nwritten in\n\tand more words";
    printf("%s\n", t);
    char s[10000];
    escape(s, t);
    printf("%s\n", s);
    unescape(t, s);
    printf("%s\n", t);
}