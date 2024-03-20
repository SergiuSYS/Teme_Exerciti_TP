#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stiva[MAX];


int isEmpty(int varf){ 
    return varf == -1;
}

int isFull(int varf){ 
    return varf == MAX -1;
}

void push(int val){
    int varf;
    if(isFull(varf)){
        printf("Stiva este plina!!");
        return;
    }
    stiva[++varf] = val; 
}

int pop(int varf){
    if(isEmpty( varf)){
        printf("Stiva este goala!!");
        return -1;
    }
    return stiva[varf--];
}

int varfStiva(int varf){
    if(isEmpty(varf)){
        printf("Stiva este goala!!");
        return -1;
    }
    return stiva[varf];
}

int main(){
    int stocare = 0,varf;
    push(6);
    while (!isEmpty(varf))
    {
        int top = varfStiva(varf);
        if(top >=12){
            stocare = top - 1;
            pop(varf);
            pop(varf);
            push(stocare);
        }
        else
            push(top + 2);
    }
    printf("%d", stocare);
    return 0;
}
