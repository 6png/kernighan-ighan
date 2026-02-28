// remove trailing blanks tabs; delete blank lines

#include <stdio.h>

#define BUF_SIZE 10000

int main() {
	int c;
	int buffer[BUF_SIZE];
	int wsCt=0, isBlankLine=1;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			wsCt=0;
		} else if (c == ' ' || c == '\t') {
			if (wsCt<BUF_SIZE) {
				buffer[wsCt++] = c;
			}
		} else {
            if (isBlankLine == 0) {
				putchar('\n');
			}
			for (int j=0; j<wsCt; j++) {
				putchar(buffer[j]);
			}
			putchar(c);
			wsCt=0;
			isBlankLine=0;
		}
	}

	if (!isBlankLine) {
		putchar('\n');
	}
}
