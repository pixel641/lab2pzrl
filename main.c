#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main() {
	char *input = NULL;
	size_t input_size = 0;
	getline(&input, &input_size, stdin);
	int check = calc(input);
	if (check == 1) {
		printf("error");
	}
	free(input);
	return 0;
}
