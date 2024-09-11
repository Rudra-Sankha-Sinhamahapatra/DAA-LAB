#include <stdio.h>
#include <string.h>

int longestCommonSubstring(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1]; 
    int maxLength = 0; 

  
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

  
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLength;
}

int main() {
    char X[] = "KIITFORKIIT";
    char Y[] = "KIITUN";

    int result = longestCommonSubstring(X, Y);
    printf("Length of Longest Common Substring: %d\n", result);

    return 0;
}
