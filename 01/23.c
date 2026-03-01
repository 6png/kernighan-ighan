// delete comments from c program txt
// *quoted string and chars

#include <stdio.h>

int main() {
    int c;
    int inSingleQuote=0, inDoubleQuote=0;
    int inLineComment=0, inBlockComment=0;

    while ((c = getchar()) != EOF) {
        if (inLineComment) { // newline ends line comment
            if (c=='\n') {
                inLineComment=0; 
                putchar(c);
            }
        } else if (inBlockComment) { // */ ends block comment
            if (c=='*') {
                c=getchar();
                if (c == '/') {
                    inBlockComment=0;
                } else if (c==EOF) {
                    return 0;
                } else {
                    ungetc(c, stdin);
                }
            }
        } else if (inSingleQuote) { // UNESCAPED ' ends char
            putchar(c);
            if (c=='\\') {
                if ((c=getchar()) == EOF) {
                    return 0;
                } else {
                    putchar(c);
                }
            } else if (c=='\'') {
                inSingleQuote=0;
            }
        } else if (inDoubleQuote) { // UNESCAPED " ends string
            putchar(c);
            if (c=='\\') {
                if ((c=getchar())==EOF) {
                    return 0;
                } else {
                    putchar(c);
                }
            } else if (c=='"') inDoubleQuote=0;
        } else { // scan for /*, //, ', "
            if (c=='/') {
                c=getchar();
                if (c=='/') inLineComment=1;
                else if (c=='*') inBlockComment=1;
                else {
                    putchar(c);
                    ungetc(c, stdin);
                }
            } else if (c=='\'') {
                inSingleQuote=1; 
            } else if (c=='"') {
                inDoubleQuote=1;
            }
            putchar(c);
        }
    }
}