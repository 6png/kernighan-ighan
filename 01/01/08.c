#include <stdio.h>

int main() {
	char c;
	int blank=0, tab=0, nl=0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			blank++;
		else if (c == '\t')
			tab++;
		else if (c == '\n')
			nl++;
	}
	printf("%d blanks, %d tabs, %d newlines", blank, tab, nl);
}
