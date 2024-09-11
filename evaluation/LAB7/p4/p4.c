#include <stdio.h>

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;   
    int j = mid + 1;
    int k = left;    
    int inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

          
            for (int t = i; t <= mid; t++) {
                printf("Inversion: (%d, %d)\n", arr[t], arr[j-1]);
            }

            inv_count += (mid - i + 1);
        }
    }


    while (i <= mid)
        temp[k++] = arr[i++];

 
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);


        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversion_count = countInversions(arr, n);
    printf("Number of inversions: %d\n", inversion_count);

    return 0;
}
