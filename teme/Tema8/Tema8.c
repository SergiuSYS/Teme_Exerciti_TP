    #include<stdio.h>
    #include<stdlib.h>
    #define MAX 1000

    void swap(int*x, int*y);  
    void quickSort(int array[], int start, int end);   
    int partitionare(int array[], int start, int end); 

int main(){
    int j = 0, num, a[MAX], length;
    int *sir = NULL;  

    FILE *arrayInput = fopen("inputArray.txt", "r"); 

    while (fscanf(arrayInput, "%d", &num) == 1 && j < MAX) {
        sir = realloc(sir, (j + 1) * sizeof(int));  
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

    void quickSort(int array[], int start, int end){
        if (start < end)
        {
            int pivot_index = partitionare(array, start, end);
            quickSort(array, start,pivot_index-1);
            quickSort(array, pivot_index+1, end);
        }
        
    }

    int partitionare(int array[], int start, int end){
        int pivot_value = array[end], i = start;

        for (int j = start; j < end; j++)
        {
            if (array[j] >= pivot_value)
            {
                swap(&array[i], &array[j]);
                i++;
            }
        }
        swap(&array[i],&array[end]);

        return i;
    }


