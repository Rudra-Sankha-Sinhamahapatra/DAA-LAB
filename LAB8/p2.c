/*
Aim of the program: Write a program to find out the Longest Common Subsequence of two given strings. Calculate length of the LCS.
Input:
Enter the first string into an array: 10010101
Enter the second string into an array: 010110110
Output:
       LCS: 100110
       LCS Length: 6
*/

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];

    // Fill dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcs_len = dp[m][n];

    char lcs_string[lcs_len + 1];
    lcs_string[lcs_len] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_string[lcs_len - 1] = X[i - 1];
            i--; j--;
            lcs_len--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs_string);
    printf("LCS Length: %d\n", dp[m][n]);
}

int main() {
    char X[50];
    char Y[50];

    printf("Enter X: ");
    scanf("%s", X);

    printf("Enter Y: ");
    scanf("%s", Y);


    findLCS(X, Y);

    return 0;
}