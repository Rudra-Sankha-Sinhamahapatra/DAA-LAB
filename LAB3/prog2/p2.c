#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500

int comparisons = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        if (pi == low || pi == high) {
            printf("Scenario: Worst-case partitioning\n");
        } else if (pi - low == high - pi) {
            printf("Scenario: Best-case partitioning\n");
        }

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void readArrayFromFile(const char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF && i < MAX_SIZE) {
        i++;
    }
    *size = i;
    fclose(file);
}

void writeArrayToFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;
    int option;

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    printf("Enter option: ");
    scanf("%d", &option);

    const char *inputFile, *outputFile;

    switch (option) {
        case 1:
            inputFile = "inAsce.dat";
            outputFile = "outQuickAsce.dat";
            break;
        case 2:
            inputFile = "inDesc.dat";
            outputFile = "outQuickDesc.dat";
            break;
        case 3:
            inputFile = "inRand.dat";
            outputFile = "outQuickRand.dat";
            break;
        default:
            printf("Exiting...\n");
            return 0;
    }

    readArrayFromFile(inputFile, arr, &size);

    printf("Before Sorting:\n");
    displayArray(arr, size);

    clock_t start_time = clock();
    quickSort(arr, 0, size - 1);
    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1e9;

    writeArrayToFile(outputFile, arr, size);

    printf("After Sorting:\n");
    displayArray(arr, size);

    printf("Number of Comparisons: %d\n", comparisons);
    printf("Execution Time: %.0f nanoseconds\n", execution_time);

    return 0;
}