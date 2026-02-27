// add print heading above table

#include <stdio.h>

int main() {
	float f, c;
	float lower=0, upper=300, step=20;

	printf("TEMP CONVERSION PROGRAM\n");

	f=lower;
	while (f <= upper) {
		c = (5.0/9.0) * (f-32.0);
		printf("%3.0f %6.1f\n", f, c);
		f += step;
	}
}
