#include <stdio.h>

int FtoC(int f) {
	return (5*(f-32))/9;
}

int main() {
	int lower=0, upper=300, step=20;
	int f=lower;
	while (f <= upper) {
		printf("%d\t%d\n", f, FtoC(f));
		f += step;
	}
}
