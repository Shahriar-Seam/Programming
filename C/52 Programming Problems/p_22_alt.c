#include <stdio.h>
#include <math.h>

// Declare array of prime and their size as global variable
#define size 100001
char ara[size];

// Eratosthenes sieve function to find primes
// This function finds all the prime numbers from 2 to 100000
// Learn more about Eratosthenes sieve function to understand this code
void sieve()
{
    // Declare variables
    int i, j, root;

    // Fill up the array with 1
    for (i = 2; i < size; i++) {
        ara[i] = 1;
    }
    
    // Don't need to check more than the root of the max number (here size)
    root = sqrt(size);

    // Sieve to put multiples of primes = 0
    for (i = 2; i <= root; i++) {
        if (ara[i] == 1) {
            // Starting from 2 as it is the smallest prime number
            for (j = 2; i * j <= size; j++) {
                ara[i * j] = 0; // Index of multiple of existing prime = 0
            }
        }
    }
}

int main()
{
    // Declare variables
    int t, i, a, b, count;
    // Sieve function finds prime numbers up to 100000 and marks their index with 1
    sieve();

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        // Get the range in which the prime numbers has to be found
        scanf("%d %d", &a, &b);
        // Initialise count to 0
        count = 0;

        // Check for primes in the range and increase count
        for (i = a; i <= b; i++) {
            // Boolean logic
            if (ara[i]) {
                count++;
            }
        }

        // Print number of primes in the range. (both upper and lower bound inclusive)
        printf("%d\n", count);
    }

    return 0;
}