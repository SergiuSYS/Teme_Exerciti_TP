#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int stiva[1001], pozitie = 1000, indice = 1000;

void pop(){
    if(indice > pozitie){
        stiva[indice] = 0;
        indice++;
    }
}

int front(){
    if (indice > pozitie)
        return stiva[indice];
}

bool empty(){
    return indice == pozitie;
}

void push(int val){
    stiva[indice] = val;
    indice--;
}

int main(){
    push(10);
    push(12);
    push(4);
    push(7);
    push(1);
    printf("%d", front());
    return 0;
}