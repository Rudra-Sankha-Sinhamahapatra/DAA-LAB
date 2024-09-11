#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubstring(char X[], char Y[], char resultStr[]) {
    int m = strlen(X);
    int n = strlen(Y);

    int result = 0;
    int endIdx = 0;  

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int len = 0;
            while (i + len < m && j + len < n && X[i + len] == Y[j + len])
                len++;
            
            if (len > result) {
                result = len;
                endIdx = i + len - 1; 
            }
        }
    }


    if (result > 0) {
        strncpy(resultStr, X + endIdx - result + 1, result);
        resultStr[result] = '\0';  
    } else {
        resultStr[0] = '\0';  
    }

    return result;
}

int main() {
    char X[] = "KIITFORKIIT";
    char Y[] = "KIITUN";
    char resultStr[100];  

    int length = longestCommonSubstring(X, Y, resultStr);
    printf("Length of the longest common substring: %d\n", length);
    printf("Longest common substring: '%s'\n", resultStr);

    return 0;
}
