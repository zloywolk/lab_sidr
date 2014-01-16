#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int init_vector(int *v[], unsigned int n);
void print_vector(char * msg, int v[], unsigned int n);
int remove_vector_even(int *src_v[], unsigned int n);
void sort_desc_vector(int *v[], unsigned int n);

int main(int argc, char *argv[]) {
	unsigned int n, m;
	int *v = NULL;

	srand((unsigned int)time(NULL));

	printf("Input num of elements of vector: ");
	if(!scanf_s("%u", &n)) {
		printf("Error of input\n");
		return -1;
	}

	init_vector(&v, n);
	print_vector("=> Source vector\n", v, n);
	m = remove_vector_even(&v, n);
	print_vector("=> Vector without even elements\n", v, m);
	sort_desc_vector(&v, m);
	print_vector("=> Sorted vector withot even elements\n", v, m);


	_getch();

	free(v);
	return 0;
}

int init_vector(int *v[], unsigned int n) {
	unsigned int i;
	*v = (int *)malloc(sizeof(int) * n);

	for(i = 0; i < n; ++i) 
		(*v)[i] = rand() % 100;

	return i;
}

void print_vector(char *msg, int v[], unsigned int n) {
	unsigned int i;

	if (v != NULL) {
		printf(msg);
		if (!n)
			printf("Zero length vector\n");
		else
			for (i = 0; i < n; ++i) 
				printf("%d%c", v[i], i < n - 1 ? ' ' : '\n');
		
	} else {
		printf("Null reference access\n");
	}
}

int remove_vector_even(int *src_v[], unsigned int n) {
	unsigned int i, m;
	int *dst_v = (int *)malloc(sizeof(int) * n);
	int *v = *src_v;

	for(i = 0, m = 0; i < n; ++i) {
		if (v[i] % 2) 
			dst_v[m++] = v[i];
	}

	free(*src_v);
	*src_v = (int *)malloc(sizeof(int) * m);
	for (i = 0; i < m; ++i)
		(*src_v)[i] = dst_v[i];

	free(dst_v);
	return m;
}

void sort_desc_vector(int *v[], unsigned int n) {
	unsigned int i, j;
	int buff;

	for (i = 0; i < n - 1; ++i) 
		for (j = i + 1; j < n; ++j)
			if ((*v)[i] < (*v)[j]) {
				buff = (*v)[i];
				(*v)[i] = (*v)[j];
				(*v)[j] = buff;
			}
}