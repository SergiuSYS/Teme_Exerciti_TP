#include <stdio.h>

int Suma_numar(int numar) {
    int suma = 0;
  
    if (numar == 0)
        return suma;

    int rest = numar % 10;
    suma += rest;
  
    return suma + Suma_numar(numar / 10);
}

int invers_numar_rec(int numar, int reversedNum) {
    if (numar == 0)
        return reversedNum;

    int lastDigit = numar % 10;

    reversedNum = (reversedNum * 10) + lastDigit;

    return invers_numar_rec(numar / 10, reversedNum);
}

int invers_numar(int numar) {
    return invers_numar_rec(numar, 0);
}


void parcurgere_inlocuire(int vector[], int size, int i) {
    if (i >= size)
        return;

    if (Suma_numar(vector[i]) % 2 == 0) {
        vector[i] = invers_numar(vector[i]);
    }

    printf("%d, ", vector[i]);
    parcurgere_inlocuire(vector, size, i + 1);
}

int main() {
    int vector[] = {20, 30, 14, 15, 12};
    int size = sizeof(vector) / sizeof(vector[0]);
    parcurgere_inlocuire(vector, size, 0);

    return 0;
}
