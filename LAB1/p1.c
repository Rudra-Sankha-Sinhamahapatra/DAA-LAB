#include<stdio.h>
#include <limits.h>

int secondsmall(int arr[],int n){
    int smallest=INT_MAX;
    int secondsmallest=INT_MAX;

    for(int i=0; i < n ;i++){
        if(smallest > arr[i]){
            smallest=arr[i];
        }
    }
    for(int i=0; i < n ;i++){
        if(arr[i] > smallest && arr[i] < secondsmallest){
            secondsmallest=arr[i];
        }
    }

    return secondsmallest;
}
int secondlarge(int arr[],int n){
    int largest=INT_MIN;
    int secondlargest=INT_MIN;

    for(int i=0; i < n ;i++){
        if(largest < arr[i]){
            largest=arr[i];
        }
    }
    for(int i=0; i < n ;i++){
        if(arr[i] < largest && arr[i] > secondlargest){
            secondlargest=arr[i];
        }
    }

    return secondlargest;


}

int main(){
    int n;
    printf("Enter the number of elements in array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int secondsmallest = secondsmall(arr,n);
     if (secondsmallest == INT_MAX) {
        printf("There is no second smallest element.\n");
    } else {
        printf("The second smallest element is %d\n", secondsmallest);
    }

    int secondLargest = secondlarge(arr , n);
    if (secondLargest == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is %d\n", secondLargest);
    }

 
    return 0;
}