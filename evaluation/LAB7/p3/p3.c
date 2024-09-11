#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findKthSmallestAndLargest(int arr[], int n, int k) {

    bubbleSort(arr, n);

    printf("The %dth smallest element is: %d\n", k, arr[k - 1]);
    printf("The %dth largest element is: %d\n", k, arr[n - k]);
}

int main() {
    int n;
    printf("Enter the array size\n");
    scanf("%d",&n);

     int arr [n];
     
    printf("Enter array elements\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

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
