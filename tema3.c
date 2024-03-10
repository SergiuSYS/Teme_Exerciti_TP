#include<stdio.h>
#include<stdlib.h>

void gasireInterschimbare(int* v, int dim, int poz) {
    int min = v[0],min_poz=0;
    for (int i = 0; i < dim; i++)
        if (i <= poz) {
            if (min > v[i]) {
                min = v[i];
                min_poz = i;
            }  
        }
        else
            break;
    int aux = v[poz];
    v[poz] = min;
    v[min_poz] = aux; 
}

int main() {
    int *vector, opt, poz, dim;
    printf("introduceti numarul de elemente: ");
    scanf("%d", &dim);
    vector = (int*)malloc(dim*sizeof(int));
    for (int i = 0; i < dim; i++)
    {
        printf("V[%d]= ", i);
        scanf("%d", vector+i);
    }
    
    while (1)
    {
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("introduceti pozitia la care se va face interschimbarea");
            scanf("%d", &poz);
            break;
        case 2:
            gasireInterschimbare(vector, dim, poz);
            printf("interschimbarea s-a efectuat");
            break;
        case 3:
            for (int i = 0; i < dim; i++)
                printf("%d ", vector[i]);
            break;
        default:
            printf("optiune gresita !!!");
            break;
        }
    }
    
    return 0;
}