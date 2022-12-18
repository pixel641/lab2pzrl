#include "hex.h"
#include <stdlib.h>
#include <string.h>

int fhex(char *num) {
    int res = 0;
    for (int i = 2; i < strlen(num); i++) {
        if (num[i] >= '0' && num[i] <= '9') {
            res = res * 16 + (num[i] - '0');
        } else if (num[i] >= 'a' && num[i] <= 'f') {
            res = res * 16 + (num[i] - 'a' + 10);
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            res = res * 16 + (num[i] - 'A' + 10);
        }
    }
    return res;
}


char *thex(int num) {
    char *res = (char *) malloc(sizeof(char));
    while (num > 0) {
        int digit = num % 16;
        if (digit >= 0 && digit <= 9) {
            res = (char *) realloc(res, (strlen(res) + 1) * sizeof(char));
            res[strlen(res)] = digit + '0';
        } else {
            res = (char *) realloc(res, (strlen(res) + 1) * sizeof(char));
            res[strlen(res)] = digit - 10 + 'A';
        }
        num /= 16;
    }

    char *res_rev = (char *) malloc(sizeof(char));
    for (int i = strlen(res) - 1; i >= 0; i--) {
        res_rev = (char *) realloc(res_rev, (strlen(res_rev) + 1) * sizeof(char));
        res_rev[strlen(res_rev)] = res[i];
    }
    free(res);
    return res_rev;
}