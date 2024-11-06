/*
22051880
CSE 27
Set 1
Q1) Given an array arr[] of size N, find the prefix sum of the array. A prefix sum
array is another array prefixSum[] of the same size, such that the value of
prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].
*/
#include <stdio.h>

void prefixSum(int arr[], int n, int prefix_sum[]) {
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefix_sum[n];

    prefixSum(arr, n, prefix_sum);

    printf("Prefix sum array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefix_sum[i]);
    }

    return 0;
}
