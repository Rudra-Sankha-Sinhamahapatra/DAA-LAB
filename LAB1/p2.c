#include<stdio.h>
int main() {
int n;
printf("Enter the size of the array\n");
scanf("%d",&n);
printf("Enter the elements of the array\n");
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

int sum=0;

int prefixSum[n];

for(int i=0;i<n;i++){
    prefixSum[i]=sum+arr[i];
    sum=prefixSum[i];
}

printf("Prefix sum:\n");
for(int i=0;i<n;i++){
    printf("%d ",prefixSum[i]);
}
return 0;
}