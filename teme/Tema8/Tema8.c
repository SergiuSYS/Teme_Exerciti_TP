    #include<stdio.h>
    #include<stdlib.h>
    #define MAX 1000

    void swap(int*x, int*y);  
    void quickSort(int array[], int low, int high);   
    int partitionare(int array[], int low, int high); 

int main(){
    int j = 0, num, a[MAX], length;
    int *sir = NULL;  

    FILE *arrayInput = fopen("inputArray.txt", "r"); 

    if (arrayInput == NULL) {
        printf("Eroare la deschiderea fisierului.");
        return -1;
    }

    while (fscanf(arrayInput, "%d", &num) == 1 && j < MAX) {
        sir = realloc(sir, (j + 1) * sizeof(int));  
        if (sir == NULL) {
            printf("Eroare la realocarea memoriei.");
            return -1;
        }
        sir[j] = num;
        j++;
    }
    length = j;

    quickSort(sir,0, length-1);

    for (int i = 0; i < length; i++)
        printf("%d ", sir[i]);

    free(sir);  
    fclose(arrayInput);
    return 0;
}

    void swap(int *x,int *y){

        int temp = *x;
        *x = *y;
        *y = temp;
    }


    void quickSort(int array[], int low, int high){
        if (low < high)
        {
            int pivot_index = partition(array, low, high);
            quickSort(array, low,pivot_index-1);
            quickSort(array, pivot_index+1, high);
        }
        
    }

    int partitionare(int array[], int low, int high){

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


