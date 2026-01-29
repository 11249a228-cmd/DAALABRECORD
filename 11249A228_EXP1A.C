#include <stdio.h>

// Recursive function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive calls for F(n-1) + F(n-2)
}

int main() {
    int terms, i;
    
    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    
    printf("Fibonacci series: ");
    for (i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));  // Print each term using recursion
    }
    printf("\n");
    
    return 0;
}
