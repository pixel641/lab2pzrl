#include "bin.h"
#include <stdlib.h>
#include <string.h>

int fbin(char *num){
	int res = 0;
	int sign = 1;
	int i = 0;
	if (num[0]== '-'){
		sign = -1;
		i =1;
	}
	for (int i = 2; i < strlen(num); i++){
		if (num[i] >= '0' && num[i] <= '1'){
			res = res*2 + (num[i]- '0');
		}
	}
	return sign * res;
}

char *tbin(int num){
	char *res = (char *) malloc(sizeof(char));
	while (num>0) {
		int  digit = num%2;
		res = (char *) realloc(res, (strlen(res)+1)*sizeof(char));
		res[strlen(res)] = digit + '0';
		num /=2;
	}
	char *res_rev = (char *) malloc(sizeof(char));
	for (int i = strlen(res) - 1; i >= 0; i--){
		res_rev = (char *) realloc(res_rev, (strlen(res_rev)+1)*sizeof(char));
		res_rev[strlen(res_rev)] = res[i];
	}
	free(res);
	return res_rev;
}
