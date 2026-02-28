// implement reverse(char[] s, int len) and use to reverse each line in input

#include <stdio.h>

#define MAX_LINE 10000

int main() {
    int c;
    int len=0;
    int s[MAX_LINE]={0};

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            reverse(s, len);
            for (int i=0; i<len; i++) {
                putchar(s[i]);
            }
            len=0;
        } else {
            s[len]=c;
            ++len;
        }
    }
    
    if (len>=0) {
        reverse(s, len);
        for (int i=0; i<len; i++) {
            putchar(s[i]);
        }
    }
}

// s[i] = *(s+i)
void reverse(int s[], int len) {
    for (int i=0; i<len/2; i++) {
        int tmp = s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=tmp;
    }
}
