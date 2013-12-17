#include <stdio.h>
#include <math.h>

double ch(double x, int n);

int main (int argc, char *argv[]) {
	double x;
	int n;

	printf("Input argument x: ");
	if(!scanf_s("%lf", &x)) {
		printf("Error input argument\n");
		return -1;
	}

	printf("Input N: ");
	if(!scanf_s("%d", &n)) {
		printf("Error input N\n");
		return -1;
	}

	if(n < 0) {
		printf("Error. Negative N\n");
		return -1;
	}

	printf("=> Expected ch(%.2f) = %.8f\n", x, cosh(x));
	printf("=> Actual ch(%.2f, %d) = %.8f\n", x, n, ch(x, n));

	return 0;
}


double ch(double x, int n) {
	double sum = 1;
	int i;
	double p;

	for(i = 2, p = x * x / 2, sum += p; i < n; ++i) 
		sum += p *= x * x / ((2 * i) * (2 * i - 1));

	return sum;
}