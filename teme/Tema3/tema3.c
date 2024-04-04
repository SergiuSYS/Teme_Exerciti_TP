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

int evaluate(int op1, int op2, char operator) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;  
        default: return 0; 
    }
}

void postfix(int FP[], int ST[], int varfFP, int varfST, char ecuatie[]) {
    char* e, x;
    e = ecuatie;
    while (*e != '\0') {
        if (isalnum(*e))
            push(*e - '0', &varfST, ST);  
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
}

int evaluatePostfix(int ST[], int varfST) {
    int op1, op2;
    char operator;
    int result;
    while (varfST != EMPTY) {
        if (isdigit(ST[varfST])) {
            push(pop(&varfST, ST), &varfST, ST); 
        }
        else {
            operator = pop(&varfST, ST);
            op2 = pop(&varfST, ST);
            op1 = pop(&varfST, ST);
            result = evaluate(op1, op2, operator);
            push(result, &varfST, ST);  
        }
    }
    return pop(&varfST, ST);  
}

int main() {
    char ecuatie[30];
    scanf("%s", ecuatie);

    int FP[LUNGIME_STIVA];
    int varfFP = EMPTY;

    int ST[LUNGIME_STIVA];
    int varfST = EMPTY;

    postfix(FP, ST, varfFP, varfST, ecuatie);

    printf("Rezultatul este: %d\n", evaluatePostfix(ST, varfST));

    return 0;
}