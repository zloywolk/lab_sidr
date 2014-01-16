#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define	BUFFSIZE 256

typedef struct __STACK_NODE {
	char *item;
	struct __STACK_NODE *pNext;
} STACK_NODE, *PSTACK_NODE;

void push(PSTACK_NODE *p, char *s);
char *pop(PSTACK_NODE *p);
void clean_memory(PSTACK_NODE *p);
char *fread_line(FILE *fd);

int main(int argc, char *argv[]) {
	FILE *fd = NULL;
	PSTACK_NODE p = NULL;
	int i;
	char *fn = (char *)malloc(sizeof(char) * BUFFSIZE);
	char *buff = (char *)malloc(sizeof(char) * BUFFSIZE);

	printf("Input filename: ");
	gets_s(fn, BUFFSIZE);

	if (!*fn) {
		printf("File name is empty\n");
		_getch();
		return -1;
	}

	if ((i = fopen_s(&fd, fn, "rt")) != 0) {
		printf("Error open file: \"%s\"\n", fn);
		_getch();
		return i;
	}

	while (fgets(buff, BUFFSIZE, fd) != NULL) 
		push(&p, buff);

	printf("=> Strings of file in reverse mode\n\n");
	for(i = 0; p; ++i) 
		printf("[%d] %s", i, pop(&p));

	fclose(fd);

	free(buff);
	free(fn);

	clean_memory(&p);

	_getch();
	return 0;
}

void push(PSTACK_NODE *p, char *s) {
	STACK_NODE head, *h;
	PSTACK_NODE pp = (PSTACK_NODE)malloc(sizeof(STACK_NODE));
	char *d;

	head.pNext = *p;
	h = *p = &head;

	d = (char *)malloc(sizeof(char) * BUFFSIZE);
	pp->item = d;

	for (; *s; *d++ = *s++);
	*d = '\0';

	pp->pNext = h->pNext;
	h->pNext = pp;

	*p = head.pNext;
}

char *pop(PSTACK_NODE *p) {
	STACK_NODE head, *h;
	PSTACK_NODE pp = NULL;

	head.pNext = *p;
	h = *p = &head;

	pp = h->pNext;

	if (pp)
		h->pNext = pp->pNext;
	else {
		*p = head.pNext;
		return NULL;
	}

	*p = head.pNext;
	return (char *)pp->item;
}

void clean_memory(PSTACK_NODE *p) {
	PSTACK_NODE d;

	while (*p) {
		d = *p;

		*p = d->pNext;
		free(d);
	}

	*p = NULL;
}