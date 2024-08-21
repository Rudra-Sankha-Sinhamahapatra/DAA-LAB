#include<stdio.h>

void decimalToBinary(int num){
    if(num==0){
        return;
    }
    decimalToBinary(num/2);
    printf("%d",num%2);
}

int main() {
int arr [100];
int n;
printf("Enter the value of n\n");
scanf("%d",&n);

printf("Enter %d elements in the array\n",n);

for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}

printf("Binary representations:\n");

for(int i=0;i<n;i++){
printf("Binary representation of %d\n",arr[i]);
decimalToBinary(arr[i]);
printf("\n");
}

return 0;
}