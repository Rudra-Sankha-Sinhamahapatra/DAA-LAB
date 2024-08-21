#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
        int id;
        char name[50];
        int age;
        int height;
        int weight;
};

void swap(struct person *a, struct person *b){
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify_weight(struct person arr[], int n, int node)
{
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != node) {
        swap(&arr[node], &arr[largest]);
        max_heapify_weight(arr, n, largest);
    }
}

// void min_heapify_weight(struct person arr[], int n, int node)
// {
//     int smallest = node;
//     int left = 2 * node + 1;
//     int right = 2 * node + 2;

//     if (left < n && arr[left].weight < arr[smallest].weight)
//         smallest = left;

//     if (right < n && arr[right].weight < arr[smallest].weight)
//         smallest = right;

//     if (smallest != node) {
//         swap(&arr[node], &arr[smallest]);
//         min_heapify_weight(arr, n, smallest);
//     }
// }

void max_heapify_age(struct person arr[], int n, int node)
{
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < n && arr[left].age > arr[largest].age)
        largest = left;

    if (right < n && arr[right].age > arr[largest].age)
        largest = right;

    if (largest != node) {
        swap(&arr[node], &arr[largest]);
        max_heapify_age(arr, n, largest);
    }
}

void min_heapify_age(struct person arr[], int n, int node)
{
    int smallest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != node) {
        swap(&arr[node], &arr[smallest]);
        min_heapify_age(arr, n, smallest);
    }
}


void max_heapSort_weight(struct person arr[], int n){
    int i;
    for (i = (n/2) - 1; i >= 0; i--)
        max_heapify_weight(arr, n, i);
}

void max_heapSort_age(struct person arr[], int n){
    int i;
    for (i = (n/2) - 1; i >= 0; i--)
        max_heapify_age(arr, n, i);

}

// void min_heapSort_weight(struct person arr[], int n){
//     int i;
//     for (i = (n/2) - 1; i >= 0; i--)
//         min_heapify_weight(arr, n, i);
// }

void min_heapSort_age(struct person arr[], int n){
    int i;
    for (i = (n/2) - 1; i >= 0; i--)
        min_heapify_age(arr, n, i);
}

void delete_root_max_heap(struct person arr[], int *n) {
    if (*n == 0) {
        printf("\nEmpty heap");
        return;
    }

    swap(&arr[0], &arr[*n - 1]);
    (*n)--;
    max_heapify_age(arr, *n, 0);
}

void insert_into_min_heap(struct person arr[], int *n, struct person new_person) {
    if (*n >= 50) {
        printf("\nHeap is full");
        return;
    }

    int index = *n;
    arr[index] = new_person;
    (*n)++;

    while (index != 0) {
        int parent = (index - 1) / 2;

        if (arr[index].age < arr[parent].age) {
            swap(&arr[index], &arr[parent]);
            index = parent;
        }
        else 
            break;
    }
}

void display(struct person p[], int n){
    printf("\nId\tName\t\tAge\tHeight\tWeight");
    for (int i = 0; i < n; i++)
        printf("\n%d\t%s\t%d\t%d\t%d", p[i].id, p[i].name, p[i].age, p[i].height, p[i].weight);
}

void main_menu(){
    printf("\n\nMAIN MENU");
    printf("\n1. Read Data");
    printf("\n2. Create a Min-heap based on the age");
    printf("\n3. Create a Max-heap based on the weight");
    printf("\n4. Display weight of the youngest person");
    printf("\n5. Insert a new person into the Min-heap");
    printf("\n6. Delete the oldest person");
    printf("\n7. Exit");
    printf("\nEnter your choice: ");
}

int main(){
    int n, i, ch;
    FILE *fp;

    int max_size = 50;

    struct person* per = (struct person*)malloc(max_size * sizeof(struct person));

    fp = fopen("students.txt", "r");
    if(fp==NULL){
        printf("\nError opening file!");
        exit(1);
    }

    printf("\nEnter n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) { 
         fscanf(fp, "%d", &per[i].id);
         fscanf(fp, "%49s", &per[i].name);
         fscanf(fp, "%d", &per[i].age);
         fscanf(fp, "%d", &per[i].weight);
         fscanf(fp, "%d", &per[i].height);
    }

    fclose(fp);

    // display(per, n);

    while(1){
        main_menu();
        scanf("%d", &ch);
        switch (ch){
        case 1:
            // Read data
            display(per, n);

            break;
        case 2:
            // Create a Min-heap based on the age
            min_heapSort_age(per, n);
            display(per, n);

            break;
        case 3:
            // Create a Max-heap based on the weight
            max_heapSort_weight(per, n);
            display(per, n);

            break;
        case 4:
            // Display weight of the youngest person
            min_heapSort_age(per, n);
            printf("\nWeight of the youngest person: %d", per[0].weight);

            break;
        case 5:
            // Insert a new person into the Min-heap
            min_heapSort_age(per, n);
            struct person new;
            printf("\nEnter ID: ");
            scanf("%d", &new.id);
            char ct[50];
            gets(ct);
            printf("\nEnter name: ");
            gets(new.name);
            printf("\nEnter age: ");
            scanf("%d", &new.age);
            printf("\nEnter height: ");
            scanf("%d", &new.height);
            printf("\nEnter weight: ");
            scanf("%d", &new.weight);

            insert_into_min_heap(per, &n, new);
            printf("\nPerson added successfully");

            break;
        case 6:
            // Delete the oldest person
            max_heapSort_age(per, n);
            printf("\nPerson ID %d deleted successfully", per[0].id);
            delete_root_max_heap(per, &n);

            break;
        case 7:
            exit(0);

            break;
        default:
            printf("\nInvalid choice");
        }
    }

    free(per);

    return 0;
}