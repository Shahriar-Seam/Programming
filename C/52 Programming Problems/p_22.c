#include <stdio.h>

// Declare array of prime and their size as global variable
#define size 100001
int array[size + 1];

// Eratosthenes sieve function to find primes
// This function finds all the prime numbers from 2 to 100000
// Learn more about Eratosthenes sieve function to understand this code
void sieve(int n1, int n2)
{
    // Declare variables
    // Initialise count to 0
    int i, j, count = 0;

    // Fill up the array from 2 to 100001
    for (i = 2; i <= size; i++) {
        array[i] = i;
    }

    // Sieve to put multiples of primes = 0
    // Starting from 2 as it is the smallest prime number
    for (i = 2; i * i <= size; i++) {
        // Don't recheck the ones already made 0
        if (array[i] != 0) {
            // The smallest multiple of next prime will always be its square
            // Then increment the index by the prime as that will be the next multiple
            // Continue the loop
            for (j = i * i; j <= size; j += i) {
                array[j] = 0;
            }
        }
    }

    // Check for primes in the range and increase count
    for (i = n1; i <= n2; i++) {
        if (array[i] != 0) {
            count++;
        }
    }
    // Print number of primes in the range. (both upper and lower bound inclusive)
    printf("%d\n", count);
}

int main()
{
    // Declare variables
    int t, i, n1, n2;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get the range
        scanf("%d %d", &n1, &n2);

        // Use sieve function to count and print primes inside that range
        sieve(n1, n2);
    }

    return 0;
}