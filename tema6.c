#include<stdio.h>

int verificare(){

}
int parcurgere(int vector[], int size){
    int i =0;
    printf("%d",vector[i]);
    if (i == size)
        return -1;
    return parcurgere(vector, i++);
    
}
int main(){
    int vector[]= {1,2,3,4,5,6,7,8,9};
    int size = sizeof(vector) / sizeof(vector[0]);
    parcurgere(vector,size);

    return 0;
}