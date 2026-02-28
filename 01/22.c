// fold lines > n cols after last non-blank char
// *lines w no whitespace

#include <stdio.h>

#define MAX_LINE    80
#define BUF_SZ      10000

int n=0;
int lastws=-1, lastnws=-1;
char buf[MAX_LINE]={0};

void fullreset() {
    n=0;
    lastws=-1;
    lastnws=-1;
}

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') { 
            printf("%.*s", n, buf);
            putchar('\n');
            fullreset();
        } else {
            if (n<80) {
                buf[n]=c;
                if (c == ' ' || c == '\t') { // track pos of last ws and non-ws chars
                    lastws=n;
                } else {
                    lastnws=n;
                }
                ++n;
            } else { // line hit 80 chars
                if (lastws!=-1) { // >=1 ws found in line
                    printf("%.*s", lastws, buf);

                    // cp stuff between last non-ws -> MAXLINE to beginning of array
                    // FOLD
                    int end=lastws+1;
                    int nn=n-end;
                    for (int i=0; i<nn; i++) {
                        buf[i] = buf[end+i];
                    }
                    fullreset();
                    n=nn;
                    // retrack new pos of last ws and non-ws char
                    for (int i=0; i<n; i++) {
                        if (buf[i]==' ' || buf[i]=='\t') {
                            lastws=i;
                        } else {
                            lastnws=i;
                        }
                    }
                } else { // no ws in line
                    printf("%.*s", MAX_LINE, buf);
                    fullreset();
                }
                ungetc(c, stdin); // re-read c on loop (instead of c+v lines 29-35)
                putchar('\n');
            }
        }
    }

    if (n>0) {
        if (lastws!=-1) {
            printf("%.*s", lastnws+1, buf);
        } else {
            printf("%.*s", n, buf);
        }
        putchar('\n');
    }
}


/* pseudo
linechars=0
lastws=-1
lastal=-1
linebuf=""

full reset 
    reset linechars=0
    reset lastws=-1
    reset lastal=-1


read char to c
    if c is newline
        print buf
        print newline
        full reset
    else
        if linechars<80
            linebuf[linechars]=c
            if c is space or tab
                set lastws=linechars
            else
                set lastal=linechars
            inc linechars
        else
            if lastws != -1
                print linebuf until lastal
            else 
                print linebuf until 80
            print newline
            full reset
            linebuf[linechars]=c
            ungetc c

if linechars>0
    if lastws != -1
        print linebuf until lastal
    else
        print linebuf until linechars
        
*/