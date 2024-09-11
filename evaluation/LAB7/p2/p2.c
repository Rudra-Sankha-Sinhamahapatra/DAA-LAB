#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, next;

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    return b;
}

int main() {
    int n;

    printf("Enter the position of Fibonacci number to display: ");
    scanf("%d", &n);

    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));

    return 0;
}
