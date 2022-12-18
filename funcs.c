#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hex.h"
#include "oct.h"
#include "bin.h"

int operation(int a, int b, char op){
	switch(op){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '&':
			return a&b;
		case '|':
			return a|b;
		case '^':
			return a^b;
		default:
			return -1;
	}
}

void print(int n, int fl){
	switch (fl){
		case 2:
			printf("%s (%d)\n", tbin(n), n);
			break;
		case 1:
			printf("%s (%d)\n", thex(n), n);
			break;
		case 0:
			printf("%s (%d)\n", toct(n), n);
			break;
		default:
			return;
	}
}

int calc(char *str){
	char *n1 = (char *) malloc(sizeof(char));
	char *n2 = (char *) malloc(sizeof(char));
	char op[1];
	int fl = 0;
	int n1_int;
	int n2_int;
	int res;

	for (int i = 0; i<strlen(str); i++){
		if (isspace(str[i])) {
			continue;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
			op[0] = str[i];
			fl = 1;
			continue;
		}
		if (fl == 0){
			n1 = (char *) realloc(n1, (strlen(n1)+1)*sizeof(char));
			n1[strlen(n1)] = str[i];
		} else {
			n2 = (char *) realloc(n2, (strlen(n2)+1)*sizeof(char));
			n2[strlen(n2)] = str[i];
		}
	}
	
	if (n1[0] == '0' && n2[0] == '0'){
		fl = 0;
		n1_int = foct(n1);
		n2_int = foct(n2);
	} else if (n1[0] == '0' && n1[1] == 'x' && n2[0] == '0' && n2[1] == 'x'){
		fl = 1;
		n1_int = fhex(n1);
		n2_int = fhex(n2);
	} else if (n1[0] == '1' && n2[0] == '1'){
		fl = 2;
		n1_int = fbin(n1);
		n2_int = fbin(n2);
	} else {
		return 1;
	}
	free(n1);
	free(n2);
	res = operation(n1_int, n2_int, op[0]);
	print(res, fl);
	return 0;
}
























