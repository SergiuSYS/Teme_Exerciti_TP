#include <stdio.h>

#define MAXN 100
#define MAXM 100
int n, m;
int h, g;

int b[MAXN][MAXM];
int a[MAXN][MAXM];

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int nrObj = 2;

void Print(int i, int j) {
    printf("(%d,%d)\n", i, j);
}

void Search(int i, int j) {
    int k;
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        Print(i, j);
    }
    else {
        for (k = 0; k < 8; k++) {
            if (a[i + dx[k]][j + dy[k]] == 0) {  
                a[i + dx[k]][j + dy[k]] = a[i][j] + 1;
                Search(i + dx[k], j + dy[k]);
            }
        }
    }
}
void FillObj(int i, int j) {
    int k;
    if (i < 0 || j < 0 || i >= MAXN || j >= MAXM)
        return;
    if (b[i][j] == 1) {
        b[i][j] = nrObj;
        for (k = 0; k < 8; k++)
            FillObj(i + dx[k], j + dy[k]);
    }
}

int main() {
    int numObjectsFound = 0;
    int x, y,k, l;


    FILE *Input_Labirint;
    FILE *Input_Fotografie;

    // AICI INCEPE PROBLEMA CU LABIRINTUL 



    Input_Labirint = fopen("inputLabirtint.txt","r");   

    // in fisier trebuie puse pe primul rand n, m cu spatiu intre EX 5 5 
    // pe linia 2 pozitia de incepere cu spatiu intre EX 1 1 
    // dupa se trece matricea care v-a fi parcursa 

    fscanf(Input_Labirint,"%d %d",&n,&m);
    fscanf(Input_Labirint,"%d %d",&x,&y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(Input_Labirint, "%d", &a[i][j]);
        }
    }
    fclose(Input_Labirint);
    Search(x, y);

   // AICI INCEPE PROBLEMA CU FOTOGRAFIA

    Input_Fotografie = fopen("inputFotografie.txt","r");

    // in fisier trebuie puse pe primul rand n, m cu spatiu intre EX 5 5 
    // dupa se trece matricea care v-a fi parcursa 

    fscanf(Input_Labirint,"%d %d",&h,&g);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < g; j++) {
            fscanf(Input_Fotografie, "%d", &b[i][j]);
        }
    }
    for (k = 0; k < MAXN; k++) {
        for (l = 0; l < MAXM; l++) {
            if (b[k][l] == 1) {
                nrObj++;
                FillObj(k, l);
                numObjectsFound++;
            }
        }
    }
    printf("Numarul de obiecte gasite: %d\n", numObjectsFound);
    fclose(Input_Fotografie);
    return 0;
}
