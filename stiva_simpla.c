#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int varf =-1;
int stiva[MAX];
int pop(){
    if(varf > 0)
        return stiva[varf--];
    else
        return -1;
}

int getTop(){
    if(varf > 0)
        return stiva[varf];
    else
        return -1;
}
void setTop(int val){
    stiva[varf] = val;
}
void push(int val){
    int varf;
    if(varf <0)
        return;
    stiva[++varf] = val; 
}


int main(){
    int stocare = 0;
    push(6);
    while (varf)
    {
        if(getTop() >=12){
            int k = pop();
            setTop(k-1);
        }
        else
        push(getTop()+2);
        printf("%d", getTop());
    }
    printf("%d", stocare);
    return 0;
}
