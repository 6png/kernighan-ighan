// remove trailing blanks tabs; delete blank lines

#include <stdio.h>

#define BUF_SIZE 10000

int main() {
	int c;
	int buffer[BUF_SIZE];
	int wsCt=0, isBlankLine=1;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (isBlankLine == 0) {
				putchar('\n');
				isBlankLine=1;
			}
			wsCt;
		} else if (c == ' ' || c == '\t') {
			if (wsCt<BUF_SIZE) {
				buffer[wsCt++] = c;
			}
		} else {
			for (int j=0; j<wsCt; j++) {
				putchar(buffer[j]);
			}
			putchar(c);
			wsCt=0;
			isBlankLine=0;
		}
	}

	if (isBlankLine==0) {
		putchar('\n');
	}
}
