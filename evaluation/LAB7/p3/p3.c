#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void findKthSmallestAndLargest(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);

    printf("The %dth smallest element is: %d\n", k, arr[k - 1]);
    printf("The %dth largest element is: %d\n", k, arr[n - k]);
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 1, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;

    printf("Enter the value of K: ");
    scanf("%d", &k);

    if (k > 0 && k <= n) {
        findKthSmallestAndLargest(arr, n, k);
    } else {
        printf("Invalid input! K should be between 1 and %d\n", n);
    }

    return 0;
}
