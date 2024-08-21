#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, mml, mmr;
    int mid;

    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    mml = findMinMax(arr, low, mid);
    mmr = findMinMax(arr, mid + 1, high);

    if (mml.min < mmr.min) {
        minmax.min = mml.min;
    } else {
        minmax.min = mmr.min;
    }

    if (mml.max > mmr.max) {
        minmax.max = mml.max;
    } else {
        minmax.max = mmr.max;
    }

    return minmax;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair minmax = findMinMax(arr, 0, n - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}
