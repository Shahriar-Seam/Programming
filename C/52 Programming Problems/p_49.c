#include <stdio.h>

void sieve(int array[], int size)
{
    // Declare variables
    int i, j;

    // Fill up the array with 1
    for (i = 2; i <= size; i++) {
        array[i] = 1;
    }

    // Sieve to put multiples of primes = 0+
    // Starting from 2 as it is the smallest prime number
    for (i = 2; i * i <= size; i++) {
        // Don't recheck the ones already made 0
        if (array[i] != 0) {
            // The smallest multiple of the next prime will always be its square
            // Then increment the index by the prime as that will be the next multiple
            // Continue the loop
            for (j = i * i; j <= size; j += i) {
                array[j] = 0;
            }
        }
    }
}

int main()
{
    // Declare variables
    int i, t;
    int size = 1000000;
    int array[size + 1];

    sieve(array, size);

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    while (t--) {
        int n;
        scanf("%d", &n);

        if (n >= 2 && n <= size && array[n] == 1) {
            printf("%d is a prime\n", n);
        }
        else {
            printf("%d is not a prime\n", n);
        }
    }

    return 0;
}
