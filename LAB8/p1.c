/*
Aim of the program: Write a program to implement the matrix chain multiplication problem using M-table & S-table to find optimal parenthesization of a matrix-chain product. Print the number of scalar multiplications required for the given input.
Note# Dimensions of the matrices can be inputted as row and column values. Validate the dimension compatibility.
*/
#include<stdio.h>
#include<stdlib.h>

void Parentheses(int i, int j, int n, int K[n][n]) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        Parentheses(i, K[i][j], n, K);
        Parentheses(K[i][j] + 1, j, n, K);
        printf(")");
    }
}

int main() {
    int n;
    printf("\nEnter the no. of matrices: ");
    scanf("%d", &n);

    int d[n + 1];
    for (int i = 0; i < (n + 1); i++) {
        printf("\nEnter d%d: ", i);
        scanf("%d", &d[i]);
    }

    int M[n][n];
    int K[n][n];

    for (int i = 0; i < n; i++) {
        M[i][i] = 0;
        K[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            M[i][j] = 999;

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];

                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    // K[i][j] = k + 1;
                    K[i][j] = k;
                }
            }
        }
    }

    printf("\n\nM Table\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                printf("%d\t", M[i][j]);
            else
                printf(" \t");
        }
        printf("\n");
    }

    printf("\n\nK Table\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                printf("%d\t", K[i][j]);
            else
                printf(" \t");
        }
        printf("\n");
    }

    printf("\nMinimum cost = %d\n", M[0][n - 1]);
    printf("\nOptimal parenthesization: ");
    Parentheses(0, n - 1, n, K);

    return 0;
}