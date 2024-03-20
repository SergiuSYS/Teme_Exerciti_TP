#include <stdio.h>
#include <stdlib.h>

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
    return 0;
}
