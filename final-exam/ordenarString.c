// create a program that reads a string and reverse it.

#include <stdio.h>
#include <string.h>

void stringSorter(char *str) {
	char chr;	
	int i, j;

	for(i = 0; i < strlen(str); i++) {
		for(j = 0; j < (strlen(str)-1); j++) {
			if(str[j] > str[j + 1]) {
				chr = str[j];
				str[j] = str[j + 1];
				str[j + 1] = chr;
			}
		}
	}
}

int main(void) {
	char input[100];

	memset(input, '\0', 100);
	fgets(input, 100, stdin);
	input[strlen(input) - 1] = '\0';
	stringSorter(input);
	printf("%s\n", input);

	return 0;
}