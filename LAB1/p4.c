#include <stdio.h>
#include <stdlib.h>

void EXCHANGE(int *arr, int p, int q) {
    int temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}


void ROTATE_RIGHT(int *arr, int p2) {
    if (p2 > 1) {
       
        int last = arr[p2 - 1];
    
        for (int i = p2 - 1; i > 0; i--) {
            EXCHANGE(arr, i, i - 1);
        }

        arr[0] = last;
    }
}

int main() {
    int N, p2;

    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));

    printf("Enter %d elements of the array: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: \t");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, p2);

    printf("After ROTATE: \t");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);

    return 0;
}
