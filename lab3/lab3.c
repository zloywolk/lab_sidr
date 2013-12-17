#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct __NODE {
	int n;
	struct __NODE *pNext;
} NODE;

void init_vector(NODE **p, int n);
void print_vector(const char *msg, NODE *p);
void clean_vector(NODE **p);
int remove_vector_even(NODE **p);
void sort_desc_vector(NODE **p);

int main(int argc, char * argv[]) {
	unsigned int n;
	NODE *p = NULL;

	srand((unsigned int)time(NULL));

	printf("Input num of elements of the serial: ");
	if (!scanf_s("%u", &n)) {
		printf("Error of input\n");
		return -1;
	}

	p = (NODE*)malloc(sizeof(NODE) * n);
	init_vector(&p, n);
	print_vector("\n=> Source vector\n", p);
	remove_vector_even(&p);
	print_vector("\n=> Source vector without even elements\n", p);
	sort_desc_vector(&p);
	print_vector("\n=> Sorted vector without even elements by descending\n", p);

	clean_vector(&p);
	return 0;
}

void init_vector(NODE **p, int n) {
	NODE head, *pp;
	*p = &head;

	for(; n > 0; --n) {
		pp = (NODE *)malloc(sizeof(NODE));
		pp->n = rand() % 100;
		pp->pNext = NULL;

		(*p)->pNext = pp;
		(*p) = (*p)->pNext;
	}

	*p = head.pNext;
}

void print_vector(const char *msg, NODE *p) {
	printf(msg);
	while(p) {
		printf("%d ", p->n);
		p = p->pNext;
	}
	printf("\n");
}

void clean_vector(NODE **p) {
	NODE *d;

	while(*p) {
		d = *p;
		(*p) = (*p)->pNext;

		free(d);
	}
}

int remove_vector_even(NODE **p) {
	NODE head, *e, *pp;
	int i = 0;

	head.pNext = *p;
	pp = &head;

	while(pp->pNext) {
		e = pp->pNext;
		if(!(e->n % 2)) {
			pp->pNext = e->pNext;
			free(e);
			++i;
		} else
			pp = pp->pNext;
	}

	*p = head.pNext;
	return i;
}

void sort_desc_vector(NODE **p) {
	NODE *pi = *p, *pj = NULL;
	int n;

	if(pi) {
		while(pi->pNext) {
			pj = pi ->pNext;
			do {
				if(pi->n < pj->n) {
					n = pi->n;
					pi->n = pj->n;
					pj->n = n;
				}

				pj = pj->pNext;
			} while (pj);
				
			pi = pi->pNext;
		}
	}
}