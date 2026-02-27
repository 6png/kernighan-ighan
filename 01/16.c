// edit main to print 
	// longest line <=10000 chars but actual length even if >10000

#include <stdio.h>
#define MAXLINE 10000

int get_line(char line[], int lim);
void copy (char to[], char from[]);

int main() {
	int len;
	int max=0;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (line[len-1] != '\n') {
			int c;
			while ((c = getchar()) != EOF) {
				++len;
				if (c == '\n') break;
			}
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max>0) {
		printf("%s\n", longest);
		printf("length: %d\n", max);
	}
}

int get_line(char s[], int lim) {
	int c, i;
	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i=0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
