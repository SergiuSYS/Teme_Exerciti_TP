#include <stdio.h>

int Suma_numar(int numar) {
  int suma = 0;

  if (numar == 0)
    return suma;

  int rest = numar % 10;
  suma += rest;

  return suma + Suma_numar(numar / 10);
}

int invers_numar(int numar) {
  if (numar == 0)
    return 0;

  int numar_inversat = 0;

  while (numar != 0) {
    int rest = numar % 10;
    numar_inversat = numar_inversat * 10 + rest;
    numar /= 10;
  }

  return numar_inversat;
}

int parcurgere_inlocuire(int vector[], int size, int i) {
  if (i >= size)
    return -1;
  if (Suma_numar(vector[i]) % 2 == 0) {
    vector[i] = invers_numar(vector[i]);
  }

  printf("%d, ", vector[i]);
  return parcurgere_inlocuire(vector, size, i + 1);
}

int main() {
  int vector[] = {20, 30, 14, 15, 12};
  int size = sizeof(vector) / sizeof(vector[0]);
  parcurgere_inlocuire(vector, size, 0);

  return 0;
}