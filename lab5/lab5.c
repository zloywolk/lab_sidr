#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define BUFFSIZE	255

char *skip_space(const char *s);
char *skip_word(const char *s);

char *even_words(const char *s);

int main(int argc, char *argv[]) {
	char *buffer = (char *)malloc(sizeof(char) * BUFFSIZE);
	char *s;

	printf("Input source string\n");
	gets_s(buffer, BUFFSIZE);

	if(*buffer) {
		s = even_words(buffer);
		printf("=> Result string (only even words)\n[%s]\n", s);
	}

	free(buffer);

	_getch();
	return 0;
}

char *skip_space(const char *s) {
	for(; (*s == ' ' || *s == '\t') && *s;  ++s);

	return (char *)s;
}

char *skip_word(const char *s) {
	for(; *s && *s != ' ' && *s != '\t'; ++s);
	return (char *)s;
}

char *even_words(const char *s) {
	char *d = (char *)malloc(sizeof(char) * BUFFSIZE);
	char *dd = d;
	int n, i = 0, m = 0;
	char *ss = (char *)s;

	*d = '\0';

	while (*(ss = skip_space(ss))) {
		n = skip_word(ss) - ss;

		if (m++ % 2) {
			if (m > 2) 
				*d++ = ' ';
			for(i = 0; i < n; ++i)
				*d++ = *ss++;
			*d = '\0';
		}
		else ss = skip_word(ss);
	}

	return dd;
}