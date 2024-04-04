#include <stdio.h>
#include <stdlib.h> // Pentru funcția abs()

#define N 6

int v[N]; // Modificăm dimensiunea vectorului v
int blocked[N][N]; // Nu mai adăugăm 1 la dimensiunile matricei
int n;

void Init(int k) {
    v[k] = -1; // Inițializăm elementele vectorului v cu -1
}

int Valid(int k) {
    for (int i = 0; i < k; i++) // Modificăm bucla pentru a începe de la 0
        if (v[i] == v[k] || abs(v[i] - v[k]) == abs(i - k))
            return 0;
    if (blocked[k][v[k]])
        return 0;
    return 1;
}

void Print() {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) { // Modificăm buclele pentru a începe de la 0
        for (int j = 0; j < n; j++) {
            if (v[i] == j)
                printf(" r ");
            else if (blocked[i][j])
                printf(" x ");
            else
                printf(" _ ");
        }
        printf("\n");
    }
}

void Back(int k) {
    k = 0; // Începem cu k = 0 în loc de k = 1
    Init(k);
    while (k >= 0) { // Modificăm condiția pentru a permite k să fie 0
        do
            v[k]++;
        while (!(v[k] >= n || Valid(k))); // Modificăm condiția pentru a permite v[k] să fie egal cu n

        if (v[k] < n) { // Modificăm condiția pentru a verifica dacă v[k] este strict mai mic decât n
            if (k == n - 1) // Modificăm condiția pentru a verifica dacă k este n - 1
                Print();
            else {
                k++;
                Init(k);
            }
        } else
            k--;
    }
}

int main() {
    printf("Enter the size of the chessboard: ");
    scanf("%d", &n);

    printf("Enter the number of blocked positions: ");
    int num_blocked;
    scanf("%d", &num_blocked);
    printf("Enter blocked positions (row col):\n");
    for (int i = 0; i < num_blocked; i++) {
        int row, col;
        scanf("%d %d", &row, &col);
        blocked[row][col] = 1;
    }

    Back(0); // Apelăm funcția Back cu k = 0

    return 0;
}
