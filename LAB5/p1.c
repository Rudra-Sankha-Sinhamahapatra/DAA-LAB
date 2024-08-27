#include<stdio.h>
#include<stdlib.h>

int w;

struct item{
    int ino;
    float profit;
    float weight;
    float pw;
    float amount;
};

void swap(struct item *a, struct item *b){
    struct item temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify_pw(struct item arr[], int n, int node)
{
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < n && arr[left].pw > arr[largest].pw)
        largest = left;

    if (right < n && arr[right].pw > arr[largest].pw)
        largest = right;

    if (largest != node) {
        swap(&arr[node], &arr[largest]);
        max_heapify_pw(arr, n, largest);
    }
}

void max_heapSort_pw(struct item arr[], int n){
    int i;
    for (i = (n/2) - 1; i >= 0; i--)
        max_heapify_pw(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify_pw(arr, i, 0);
    }

    for (i = 0; i < n / 2; i++)
        swap(&arr[i], &arr[n - i - 1]);

}

void display(struct item arr[], int n){
    printf("\nINO\tPROFIT\t\tWEIGHT\t\tAMOUNT\t\tPW Ratio");
    for (int i = 0; i < n; i++){
        printf("\n%d\t%f\t%f\t%f\t%f", arr[i].ino, arr[i].profit, arr[i].weight, arr[i].amount, arr[i].pw);
    }
}

float calculate_profit(struct item arr[], int n){
    for (int i = 0; i < n; i++){
        if(w<=0)
            break;
        else{
            if(arr[i].weight <= w){
                w = w - arr[i].weight;
                arr[i].amount = 1;
            }
            else{
                arr[i].amount = w / arr[i].weight;
                w = 0;
            }
        }
    }
    float profit = 0;
    for (int i = 0; i < n; i++){
        profit += (arr[i].profit * arr[i].amount);
    }
    return profit;
}

int main(){
    int n;
    printf("\nEnter capacity of the knapsack: ");
    scanf("%d", &w);
    printf("\nEnter n: ");
    scanf("%d", &n);

    struct item a[n];

    for (int i = 0; i < n; i++ ){
        a[i].ino = i + 1;
        printf("\nEnter the profit and weight of item no %d: ", a[i].ino);
        scanf("%f %f", &a[i].profit, &a[i].weight);
        a[i].pw = a[i].profit/a[i].weight;
        a[i].amount = 0;
    }

    max_heapSort_pw(a, n);
    // display(a, n);

    calculate_profit(a, n);

    float max_profit = calculate_profit(a, n);
    display(a, n);
    printf("\nMax. profit = %f", max_profit);

    return 0;
}