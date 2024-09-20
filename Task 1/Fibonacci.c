#include <stdio.h>

// Global array to store computed Fibonacci numbers for memoization
long long int g_fib[10005] = {}; // Initialized to 0

// Function to compute the nth Fibonacci number using recursion and memoization
// Parameters:
// - i: The index of the Fibonacci number to compute
// Returns: The nth Fibonacci number
long long int fibonacci(int i) {
    // Base case: return i for Fibonacci(0) and Fibonacci(1)
    if (i < 2) {
        return i;
    }

    // Check if the Fibonacci number has already been computed
    if (g_fib[i] > 0) {
        return g_fib[i]; // Return the cached value
    }

    // Compute the Fibonacci number recursively and store it in the global array
    g_fib[i] = fibonacci(i - 1) + fibonacci(i - 2);
    return g_fib[i]; // Return the computed Fibonacci number
}

int main() {
    // Local variable declaration for loop control
    int i;

    // Print the first 50 Fibonacci numbers
    for (i = 0; i < 50; i++) {
        printf("%lld\n", fibonacci(i)); // Print each Fibonacci number
    }

    return 0; // Indicate that the program ended successfully
}
