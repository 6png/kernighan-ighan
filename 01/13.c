#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 45

int main() {
	int c;
	int charCt=0;
	int freqs[MAX_WORD_LENGTH]={0};

	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			++charCt;
		} else {
			if (charCt!=0) {
				++freqs[charCt-1];
			}
			charCt=0;
		}
	}

	for (int i=0; i<MAX_WORD_LENGTH; i++) {
		printf("%6d: ", i);
		for (int j=0; j<freqs[i]; j++) {
			putchar('|');
		}
		printf("\n");
	}
}
