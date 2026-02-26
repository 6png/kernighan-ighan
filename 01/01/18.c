#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		int isBlankLine=1;
		int pastFirstNonBlank=0;
		while ((c = getchar()) != '\n') {
			if ((c != ' ' && c != '\t') || pastFirstNonBlank) {
				putchar(c);
				isBlankLine=0;
				pastFirstNonBlank=1;
			}
		}
		if (!isBlankLine) {
			putchar('\n');
		}
	}
}
