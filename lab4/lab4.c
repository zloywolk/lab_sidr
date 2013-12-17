#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE	255

char *skip_space(const char *s);
char *skip_word(const char *s);

char *remove_even_words(const char *s);
void sort_words_alpha(char **mw, int m);
int compare_str(const char *s, const char *d);
int copy_str(char *d, const char *s);
char *concat_words(char **s, int m);

int main(int argc, char *argv[]) {
	char *buffer = (char *)malloc(sizeof(char) * BUFFSIZE);
	char *s;

	printf("Input source string\n");
	gets_s(buffer, BUFFSIZE);

	if(*buffer) {
		s = remove_even_words(buffer);
		printf("=> Result string\n<%s>\n", s);
	}

	free(buffer);
	return 0;
}

int length(const char *s) {
	int i = 0;
	for(; *s; ++i, s++);

	return i;
}

char *skip_space(const char *s) {
	for(; (*s == ' ' || *s == '\t') && *s;  ++s);

	return (char *)s;
}

char *skip_word(const char *s) {
	for(; *s && *s != ' ' && *s != '\t'; ++s);
	return (char *)s;
}

char *remove_even_words(const char *s) {
	char *d = (char *)malloc(sizeof(char) * BUFFSIZE);
	int n, i = 0, m = 0;
	char *ss = (char *)s;
	char **buff = (char **)malloc(sizeof(char *) * BUFFSIZE * BUFFSIZE);

	*d = '\0';

	while (*(ss = skip_space(ss))) {
		if((n = skip_word(ss) - ss) % 2) {
			buff[m] = (char *)malloc(sizeof(char) * BUFFSIZE);
			for(i = 0; i < n; ++i)
				buff[m][i] = *ss++;
			buff[m++][i] = '\0';
		}
		else ss = skip_word(ss);
	}

	sort_words_alpha(buff, m);
	d = concat_words(buff, m);

	for(i = 0; i < m; ++i)
		free(buff[i]);

	free(buff);

	return d;
}

void sort_words_alpha(char **mw, int m) {
	char *temp = (char *)malloc(sizeof(char) * BUFFSIZE);
	int i, j;

	for(i = 0; i < m - 1; ++i) {
		for(j = i + 1; j < m; ++j) {
			if(compare_str(mw[i], mw[j]) > 0) {
				copy_str(temp, mw[i]);
				copy_str(mw[i], mw[j]);
				copy_str(mw[j], temp);
			}
		}
	}

	free(temp);
}

int compare_str(const char *s, const char *d) {
	for(; (*s || *d) && *s == *d; s++, d++);
	return *s - *d;
}

int copy_str(char *d, const char *s) {
	int i;
	/*d = (char *)realloc(d, sizeof(char) * (length(s) + 1));*/
	for(i = 0; i < *s; ++i)
		d[i] = *s++;
	d[i] = '\0';

	return i;
}

char *concat_words(char **s, int m) {
	int i, j;
	char *d = (char *)malloc(sizeof(char) * BUFFSIZE);

	for(i = 0, j = 0; i < m; ++i) {
		j += copy_str(&d[j], s[i]);
		d[j++] = ' ';
	}
	d[--j] = '\0';

	return d;
}