#include<stdio.h>
#include<stdlib.h>


void gasireInterschimbare(int *v,int dim, int poz){
    int min = v[0],i;
    for (i = 0; i < dim; i++)
        if (i<=poz)
            if (min > v[i])
                min = v[i];
        else
            break;
    int aux = *(v+poz);
    *(v+poz)= v[i];
    v[i] = aux;
}

int main(){
    int vector[] = {1,2,3,4,5,6,7};
    int dim = sizeof(vector);
    int poz =4;

    gasireInterschimbare(vector,dim,poz);

    for (int i = 0; i < dim; i++)
        printf("%d ",vector+i);
    
    return 0;
}