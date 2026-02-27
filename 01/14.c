// histogram of char frequencies

#include <stdio.h>
#include <limits.h>

int main() {
	int freqs[UCHAR_MAX + 1] = {0};
	int c;
	while ((c = getchar()) != EOF) {
		++freqs[(unsigned char)c];
	}
	for (int i=0; i<UCHAR_MAX+1; i++) {
		if (i >= 32 && i <= 126) {
			printf("%c : %d\n", i, freqs[i]);
		}
	}
}
