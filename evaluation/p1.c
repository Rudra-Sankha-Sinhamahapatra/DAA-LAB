#include<stdio.h>


int search(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
   int n;
    printf("Enter the length of the array\n");
    scanf("%d",&n);
    int arr [n];

    printf("Enter the elements of the array\n");

for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

int target;
printf("Enter the element to search\n");
scanf("%d",&target);

int res=search(arr,n,target);

if(res==-1){
    printf("element not found");
}
else {
    printf("element found at index %d",res);
}
}