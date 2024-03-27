#include <stdio.h>

#define N 6

int v[N + 1]; 
int blocked[N + 1][N + 1]; 
int n; 

void Init(int k) {
    v[k] = 0;
}

int Valid(int k) {
    for (int i = 1; i < k; i++) 
        if (v[i] == v[k] || abs(v[i] - v[k]) == abs(i - k)) 
            return 0; 
    if (blocked[k][v[k]]) 
        return 0;
    return 1;
}

void Print() {
    printf("\nSolution:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
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
    k = 1; 
    Init(k);
    while (k > 0) {
        do
            v[k]++;
            while (!(v[k] > n || Valid(k))); 

        if (v[k] <= n) { 
            if (k == n)  
                Print(); 
            else {
                k++; 
                Init(k); 
            }
        }
        else
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

    Back(1); 

    return 0;
}

// modifica sa porneasca sirul de la 0 nu de la 1
