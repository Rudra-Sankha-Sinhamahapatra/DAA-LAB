#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n;

    printf("Enter an even number of integers: ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Please enter an even number of integers.\n");
        return 1;
    }

    int numbers[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n; i += 2) {
        int num1 = numbers[i];
        int num2 = numbers[i + 1];
        printf("The GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    }

    return 0;
}
