#include <stdio.h>

int main() {
	float f, c;
	float lower=0, upper=300, step=20;

	printf("TEMP CONVERSION PROGRAM\n");

	c=lower;
	while (c <= upper) {
		f = (c * 1.8) + 32;
		printf("%3.0f %6.1f\n", c, f);
		c += step;
	}
}
