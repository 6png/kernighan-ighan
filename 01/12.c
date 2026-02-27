// print input one word per line

#include <stdio.h>

int main() {
	int c, inWord=0; // missed initialization

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (inWord) {
				putchar('\n');
				inWord=0;
			}
		} else {
			putchar(c);
			inWord=1;
		}
	}
}
