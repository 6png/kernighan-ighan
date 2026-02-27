// output input with only single spaces
// eg all multi-whitespace stretches replaced with single space

#include <stdio.h>

int main() {
	char c=getchar(), prev=c;
	while ((c = getchar()) != EOF) {
		if (!(c==' ' && prev==c)) {
			putchar(prev);
		}
		prev=c;
	}
}
