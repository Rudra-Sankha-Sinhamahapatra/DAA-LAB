#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubstring(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);

    int result = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int len = 0;
            while (i + len < m && j + len < n && X[i + len] == Y[j + len])
                len++;
            result = max(result, len);
        }
    }

    return result;
}

int main() {
    char X[] = "KIITFORKIIT";
    char Y[] = "KIITUN";

    int length = longestCommonSubstring(X, Y);
    printf("Length of the longest common substring: %d\n", length);

    return 0;
}