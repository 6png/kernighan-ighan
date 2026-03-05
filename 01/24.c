// return error or not based on matching (), [], {}
    // dont forget quotes, escape sequences, comments

#include <stdio.h>

#define BUF_SZ  10000

typedef enum { OUTQUOCOM = 0, 
                INCHARQUO, INSTRQUO,
                INLINECOM, INBLOCKCOM } QuoComStatus;

int matches (char a, char b) {
    return (a=='(' && b==')') || 
            (a=='[' && b==']') || 
            (a=='{' && b=='}');
}

int main() {
    QuoComStatus status = OUTQUOCOM;
    int c;
    int brktQ[BUF_SZ], n=-1;
    

    while ((c = getchar()) != EOF) {
        if (status == INLINECOM) {
            if (c=='\n') {
                status = OUTQUOCOM;
            }
        } else if (status == INBLOCKCOM) {
            if (c=='*') {
                c=getchar();
                if (c=='/') {
                    status = OUTQUOCOM;
                } else if (c==EOF) {
                    return 0;
                } else {
                    ungetc(c, stdin);
                }
            }
        } else if (status == INCHARQUO) {
            if (c=='\\') {
                if ((c=getchar()) == EOF) {
                    return 0;
                }
            } else if (c=='\'') {
                status = OUTQUOCOM;
            }
        } else if (status == INSTRQUO) {
            if (c=='\\') {
                if ((c=getchar()) == EOF) {
                    return 0;
                } 
            } else if (c=='"') {
                status = OUTQUOCOM;
            }
        } else {
            if (c=='/') {
                c=getchar();
                if (c=='/') {
                    status = INLINECOM;
                } else if (c=='*') {
                    status = INBLOCKCOM;
                } else {
                    ungetc(c, stdin);
                }
            } else if (c=='\'') {
                status = INCHARQUO;
            } else if (c=='"') {
                status = INSTRQUO;
            } else {        // the only part not in 23: typical q logic 
                if (c=='(' || c=='[' || c=='{') {
                    brktQ[++n] = c;
                } else if (c==')' || c==']' || c=='}') {
                    if (n > -1 && matches(brktQ[n], c)) {
                        --n;
                    } else {
                        printf("error: mismatched/missing brkt\n");
                        return 0;
                    }
                }
            }
        }
    }

    if (n!=-1) {
        printf("error: mismatched/missing closing brkt\n");
    } else if (status != OUTQUOCOM && status != INLINECOM) {
        printf("error: unclosed quote/comment\n");
    } else {
        printf("no errors\n");
    }
}