#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
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
=======

#define MAX 100

int varf =-1;
int stiva[MAX];

int isEmpty(){ 
    if (varf  == -1)
        return 0;
    else
        return 1;
}

int isFull(){ 
    if(varf == MAX -1)
        return 0;
    else
        return 1;
}

void push(int val){
    if(isFull()){
        printf("Stiva este plina!!");
        return;
    }
    stiva[++varf] = val; 
}

int pop(){
    if(isEmpty()){
        printf("Stiva este goala!!");
        return -1;
    }
    return stiva[varf--];
}

int varfStiva(){
    if(!isEmpty()){
        printf("Stiva este goala!!");
        return -1;
    }
    return stiva[varf];
}

int main(){
    int stocare = 0;
    push(6);
    while (!isEmpty())
    {
        int top = varfStiva();
        if(top >=12){
            stocare = top - 1;
            pop();
            pop();
            push(stocare);
        }
        else
            push(top + 2);
    }
    printf("%d", stocare);
>>>>>>> f51443f922411ca1af20b614a192f2292a25f1d6
    return 0;
}
