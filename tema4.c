#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LUNGIME_STIVA 100
#define EMPTY -1

int push(int val, int* varf, int stiva[]) {
    if (*varf >= LUNGIME_STIVA - 1)
        return 0;
    (*varf)++;
    stiva[*varf] = val;
    return 1;
}

int pop(int* varf, int stiva[]) {
    if (*varf == EMPTY)
        return EMPTY;
    int result = stiva[*varf];
    (*varf)--;
    return result;
}

int getTop(int varf, int stiva[]) {
    if (varf != EMPTY)
        return stiva[varf];
    else
        return -1;
}

void printStack(int varf, int stiva[]) {
    for (int i = 0; i <= varf; i++) {
        printf("%c ", stiva[i]);
    }
    printf("\n");
}

int priority(char x) {
    switch (x) {
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return -1;
    }
}

void postfix(int FP[], int ST[], int varfFP, int varfST, char ecuatie[]) {
    char* e, x;
    e = ecuatie;
    while (*e != '\0') {
        if (isalnum(*e))
            push(*e, &varfST, ST);
        else if (*e == '(')
            push(*e, &varfFP, FP);
        else if (*e == ')') {
            while ((x = pop(&varfFP, FP)) != '(')
                push(x, &varfST, ST);
        }
        else {
            while (varfFP != EMPTY && priority(getTop(varfFP, FP)) >= priority(*e))
                push(pop(&varfFP, FP), &varfST, ST);
            push(*e, &varfFP, FP);
        }
        e++;
    }
    while (varfFP != EMPTY)
        push(pop(&varfFP, FP), &varfST, ST);
    printStack(varfST, ST);
}

int main() {
    char ecuatie[30];
    scanf("%s", ecuatie);

    int FP[LUNGIME_STIVA];
    int varfFP = EMPTY;

    int ST[LUNGIME_STIVA];
    int varfST = EMPTY;

    postfix(FP, ST, varfFP, varfST, ecuatie); 
    return 0;
}
