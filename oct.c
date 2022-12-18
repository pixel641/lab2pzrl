#include "oct.h"
#include <string.h>
#include <stdlib.h>

char* toct(int num) {
    char* res = (char*)malloc(sizeof(char));
    while (num > 0) {
        int digit = num % 8;
        res = (char*)realloc(res, (strlen(res) + 1) * sizeof(char));
        res[strlen(res)] = digit + '0';
        num /= 8;
    }

    char* res_rev = (char*)malloc(sizeof(char));
    for (int i = strlen(res) - 1; i >= 0; i--) {
        res_rev = (char*)realloc(res_rev, (strlen(res_rev) + 1) * sizeof(char));
        res_rev[strlen(res_rev)] = res[i];
    }
    free(res);
    return res_rev;
}

int foct(char *num) {
    int res = 0;
    for (int i = 1; i < strlen(num); i++) {
        if (num[i] >= '0' && num[i] <= '7') {
            res = res * 8 + (num[i] - '0');
        }
    }
    return res;
}