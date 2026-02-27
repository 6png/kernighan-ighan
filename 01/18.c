// remove trailing blanks tabs; delete blank lines

#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		int isBlankLine=1;
		while ((c = getchar()) != '\n') {
			if (c != ' ' && c != '\t') {
				putchar(c);
				isBlankLine=0;
			}
		}
		if (!isBlankLine) {
			putchar('\n');
		}
	}
}
