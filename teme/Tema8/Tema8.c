#include<stdio.h>
#define MAX 1000

// CHEMAReA FUNCTIILOR NECESARE PENTRU ALGORITM

void swap(int*x, int*y); // functie pentru interschimbare
void quickSort(int array[], int lenght); // functie pentru utilizator pentru a nu a fi nevoit sa introduca valuare minima si maxima
void quickSort_recursivitate(int array[], int low, int high); //algoritmul de quick sort in sine 
int partition(int array[], int low, int high); 

int main(){
    int j = 1,num,a[MAX],lenght;
    FILE * arrayInput;

    // IMPORTANT in fisier primul numar va fi marimea sa
    arrayInput = fopen("inputArray.txt", "r");

    fscanf(arrayInput, "%d", &lenght);
    while (fscanf(arrayInput, "%d", &num) == 1 && j < MAX) {
        a[j] = num;
        j++;
    }

    quickSort(a,lenght);

    for (int i = 0; i < lenght; i++)
        printf("%d ", a[i]);

    fclose(arrayInput);
    return 0;
}


void swap(int *x,int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(int array[], int lenght){

    quickSort_recursivitate(array, 0, lenght-1);
}

void quickSort_recursivitate(int array[], int low, int high){
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quickSort_recursivitate(array, low,pivot_index-1);
        quickSort_recursivitate(array, pivot_index+1, high);
    }
       
}

int partition(int array[], int low, int high){

    int pivot_value = array[high];

    int i = low; 
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i],&array[high]);

    return i;
}
