    #include<stdio.h>
    #include<stdlib.h>
    #define MAX 1000

    // CHEMAREA FUNCTIILOR NECESARE PENTRU ALGORITM

    void swap(int*x, int*y); // functie pentru interschimbare
    void quickSort(int array[], int lenght); // functie pentru utilizator pentru a nu a fi nevoit sa introduca valuare minima si maxima
    void quickSort_recursivitate(int array[], int low, int high); //algoritmul de quick sort in sine 
    int partition(int array[], int low, int high); 

int main(){
    int j = 0, num, a[MAX], length;
    int *sir = NULL; // Inițializează sir cu NULL

    FILE *arrayInput = fopen("inputArray.txt", "r");// in fisier se v a trece un numar pe fiecare linie 

    if (arrayInput == NULL) {
        printf("Eroare la deschiderea fisierului.");
        return -1;
    }

    while (fscanf(arrayInput, "%d", &num) == 1 && j < MAX) {
        sir = realloc(sir, (j + 1) * sizeof(int)); // Realocă memoria pentru sir
        if (sir == NULL) {
            printf("Eroare la realocarea memoriei.");
            return -1;
        }
        sir[j] = num;
        j++;
    }
    length = j;

    quickSort(sir, length);

    for (int i = 0; i < length; i++)
        printf("%d ", sir[i]);

    free(sir); // Eliberează memoria alocată pentru sir
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
            if (array[j] >= pivot_value)
            {
                swap(&array[i], &array[j]);
                i++;
            }
        }
        swap(&array[i],&array[high]);

        return i;
    }


