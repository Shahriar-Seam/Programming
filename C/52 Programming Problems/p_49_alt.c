#include <stdio.h>
#include <math.h>

// Function to generate primes using the Sieve of Eratosthenes algorithm
void sieve(int array[], int size)
{
    // Declare variables
    int i, j;

    // Fill up the array with numbers starting from 2
    for (i = 2; i <= size; i++) {
        array[i] = i;
    }

    // Sieve to put multiples of primes = 0+
    // Starting from 2 as it is the smallest prime number
    for (i = 2; i * i <= size; i++) {
        // Don't recheck the ones already marked as 0
        if (array[i] != 0) {
            // The smallest multiple of the next prime will always be its square
            // Then increment the index by the prime as that will be the next multiple
            // Continue the loop to mark all multiples of the current prime as 0
            for (j = i * i; j <= size; j += i) {
                array[j] = 0;
            }
        }
    }
}

int main()
{
    // Initialize an array to store prime numbers generated by the sieve function
    int prime_ara[1000000];

    int T, sqrt_n, i;
    long long int N;

    // Generate the prime numbers using the sieve function
    sieve(prime_ara, 1000000);

    // Read the number of test cases
    scanf("%d", &T);

    // Process each test case
    while (T--) {
        // Read the number for the current test case
        scanf("%lld", &N);

        // If the number is negative, skip to the next test case
        if (N < 0) {
            continue;
        }

        // Calculate the square root of the number
        sqrt_n = sqrt(N);

        // Assume the number is prime until proven otherwise
        int is_prime = 1;

        // Check if the number is divisible by any of the generated primes up to the square root
        for (i = 0; prime_ara[i] <= sqrt_n; i++) {
            // Skip numbers that were marked as 0 in the sieve
            if (prime_ara[i] == 0) {
                continue;
            }

            // If the number is divisible by any prime, it is not a prime
            if (N % prime_ara[i] == 0) {
                is_prime = 0;
                break;
            }
        }

        // Print the result for the current test case
        if (is_prime == 1) {
            printf("%lld is a prime\n", N);
        } else {
            printf("%lld is not a prime\n", N);
        }
    }

    return 0;
}
