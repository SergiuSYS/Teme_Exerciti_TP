#include <stdio.h>

#define MAXN 100
#define MAXM 100

int n, m;
int a[MAXN][MAXM];
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

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

int main() {
    printf("Introduceti numarul de linii si coloane ale labirintului: ");
    scanf_s("%d %d", &n, &m);

    printf("Introduceti matricea labirintului (0 - spatiu liber, 1 - zid), separate prin spatii si cu un nou rand dupa fiecare linie:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    int x, y;
    printf("Introduceti coordonatele punctului initial: ");
    scanf_s("%d %d", &x, &y);

    Search(x, y);

    return 0;
}
