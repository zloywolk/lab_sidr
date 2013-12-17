#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned int n, sn;
	unsigned int d, s, d_min, d_max;
	unsigned int n_min, n_max;

	printf("Input n: ");
	if (!scanf_s("%u", &n))
	{
		printf("Incorrect integer format\n");
		return -1;
	}
	/* ¬озможно понадобитс€ проверка на переполнение unsigned int */

	d = d_min = d_max = n % 10;
	for (sn = n / 10, d = sn % 10; sn > 0; sn /= 10, d = sn % 10) {
		d_min = d < d_min ? d : d_min; 
		d_max = d > d_max ? d : d_max;
	}

	for (sn = n, n_max = 0, n_min = 0; sn > 0; sn /= 10) {
		d = sn % 10;
		if(d == d_min) ++n_min;
		if(d == d_max) ++n_max;
	}

	if(d_max - d_min)
		s = d_min * n_min + d_max * n_max;
	else
		s = d_min * n_min;

	printf("Result for %u: %u\n", n, s);
	return 0;
}