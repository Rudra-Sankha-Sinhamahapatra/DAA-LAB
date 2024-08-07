#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparison_count = 0;


void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int read_array_from_file(const char *filename, int arr[], int max_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF && i < max_size) {
        i++;
    }

    fclose(file);
    return i; 
}

void write_array_to_file(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    int arr[500];  
    int n;        

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    const char *input_file;
    const char *output_file;

    switch (choice) {
        case 1:
            input_file = "inAsce.dat";
            output_file = "outMergeAsce.dat";
            break;
        case 2:
            input_file = "inDesc.dat";
            output_file = "outMergeDesc.dat";
            break;
        case 3:
            input_file = "inRand.dat";
            output_file = "outMergeRand.dat";
            break;
        default:
            printf("Exiting...\n");
            return 0;
    }

    n = read_array_from_file(input_file, arr, 500);

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    clock_t start_time = clock();
    merge_sort(arr, 0, n - 1);
    clock_t end_time = clock();

    write_array_to_file(output_file, arr, n);

    printf("After Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1e9;

    printf("Number of Comparisons: %lld\n", comparison_count);
    printf("Execution Time: %.0f nanoseconds\n", execution_time);

    return 0;
}
