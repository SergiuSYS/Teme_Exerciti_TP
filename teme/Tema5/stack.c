#include <stdio.h>
#include <stdlib.h>

#define LUNGIME_STIVA 100
#define EMPTY -1

int stiva[LUNGIME_STIVA];
int varf = EMPTY;

int push(int val) {
    if (varf >= LUNGIME_STIVA - 1)
        return 0;
    varf++;
    stiva[varf] = val;
    return 1;
}

int pop() {
    if (varf == EMPTY)
        return EMPTY;
    int result = stiva[varf];
    varf--;
    return result;
}

int getTop() {
    if (varf != EMPTY)
        return stiva[varf];
    else
        return -1;
}

void printStack() {
    for (int i = 0; i <= varf; i++) {
        printf("%d ", stiva[i]);
    }
    printf("\n");
}


int main() {
    int stocare = 0;
    push(6);
    while (varf != -1)
    {
        int top = getTop();
        if (top >= 12) {
            stocare = top - 1;
            pop();
            if (varf == -1)
                break;
            pop();
            push(stocare);
        }
        else
            push(top + 2);
    }
    printf("%d", stocare);
    return 0;
}
