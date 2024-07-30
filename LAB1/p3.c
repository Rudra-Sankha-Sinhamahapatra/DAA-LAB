#include <stdio.h>
#include <stdlib.h>

void readNumbersFromFile(int arr[], int n, const char *filename);
void findDuplicatesAndMostRepeating(int arr[], int n, int *totalDuplicates, int *mostRepeating);

int main() {
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int arr[n];
    readNumbersFromFile(arr, n, "numbers.txt");

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int totalDuplicates = 0;
    int mostRepeating = 0;
    findDuplicatesAndMostRepeating(arr, n, &totalDuplicates, &mostRepeating);

    printf("Total number of duplicate values = %d\n", totalDuplicates);
    printf("The most repeating element in the array = %d\n", mostRepeating);

    return 0;
}

void readNumbersFromFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading number from file.\n");
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

void findDuplicatesAndMostRepeating(int arr[], int n, int *totalDuplicates, int *mostRepeating) {
    int count[n];

    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }

    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            *mostRepeating = arr[i];
        }
        if (count[i] > 0) {
            (*totalDuplicates)++;
        }
    }
}
