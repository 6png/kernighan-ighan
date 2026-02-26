#include <stdio.h>

int main() {
	int c, charCt=0;
	int line[80];
	int i=0;
	while ((c = getchar()) != EOF) {
		if (c != '\n' && i<80) {
			line[i]=c;
			++i;
		} else {
			if (i == 80) {
				for (int j=0; j<80; j++) {
					putchar(line[j]);
				}
				while ((c = getchar()) != '\n') {
					putchar(c);
				}
			}
			i=0;
		}
	}
}
