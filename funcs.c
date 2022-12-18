#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hex.h"
#include "oct.h"
#include "bin.h"


int operation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '&':
            return a & b;
        case '|':
            return a | b;
        case '^':
            return a ^ b;
        default:
            return -1;
    }
}

void print(int n, int fl) {
    char *res;
    int len;
    int sign = 1;
    if (n < 0) {
        sign = -1;
        printf("-");
    }

    switch (fl) {
        case 0:
            res = to_hex(n * sign);
            len = strlen(res);
            if (len) {
                printf("0x%s (%d)\n", res, n);
            } else {
                printf("0x0 0\n");
            }
            break;
        case 1:
            res = to_oct(n * sign);
            len = strlen(res);
            if (len) {
                printf("0%s (%d)\n", res, n);
            } else {
                printf("00 0\n");
            }
            break;
        case 2:
            res = to_bin(n * sign);
            len = strlen(res);
            if (len) {
                printf("%s (%d)\n", res, n);
            } else {
                printf("0 0\n");
            }
            break;
        default:
            return;
    }
    free(res);
}

int check_system(char *str) {
    int i = 0;
    if (str[0] == '-') {
        i = 1;
    }
    if (str[i] == '0' && str[i + 1] == 'x') {
        return 0;
    } else if (str[i] == '0') {
        return 1;
    } else {
        return 2;
    }
}

int convert(char *str, int fl) {
    switch (fl) {
        case 0:
            return from_hex(str);
        case 1:
            return from_oct(str);
        case 2:
            return from_bin(str);
        default:
            return -1;
    }
}

int for_one_number(char *str) {
    char number[128];
    memset(number, 0, sizeof(number));

    for (int i = 1; i < strlen(str); i++) {
        if (isspace(str[i])) {
            continue;
        }
        number[strlen(number)] = str[i];
    }

    int flag = check_system(str);
    int num = convert(number, flag);

    print(~num, flag);

    return 0;
}

int for_two_numbers(char *str) {
    char num1[128];
    char num2[128];
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));

    char op;
    int fl = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            continue;
        }
        if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '&' || str[i] == '|' ||
             str[i] == '^') && fl == 1) {
            op = str[i];
            fl = 2;
            continue;
        }
        if (fl == 0 || fl == 1) {
            fl = 1;
            num1[strlen(num1)] = str[i];
        } else {
            num2[strlen(num2)] = str[i];
        }
    }

    int fl1 = check_system(num1);
    int fl2 = check_system(num2);
    if (fl1 != fl2) {
        return 1;
    }

    int num1 = convert(num1, fl1);
    int num2 = convert(num2, fl2);

    int result = operation(num1, num2, op);
    print(result, fl1);

    return 0;
}

int calculator(char *str) {
    if (str[0] == '~') {
        return for_one_number(str);
    } else {
        return for_two_numbers(str);
    }
}
