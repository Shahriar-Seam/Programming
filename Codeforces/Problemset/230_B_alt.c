#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define yes printf("YES\n")
#define no printf("NO\n")

bool *sieve;
int *primes;
int prime_count;

void initialize_sieve(int size)
{
    sieve = (bool *)malloc((size + 1) * sizeof(bool));
    primes = (int *)malloc(size * sizeof(int));

    memset(sieve, true, (size + 1) * sizeof(bool));
    sieve[0] = sieve[1] = false;
    prime_count = 0;

    for (int p = 2; p * p <= size; p++)
    {
        if (sieve[p])
        {
            for (int i = p * p; i <= size; i += p)
            {
                sieve[i] = false;
            }
            primes[prime_count++] = p;
        }
    }
}

int T_Prime(unsigned long long int n)
{
    unsigned long long int root = (unsigned long long int)sqrt(n);

    if (n < 1000000)
    {
        for (int i = 0; i < prime_count; i++)
        {
            if (root == primes[i])
            {
                return 1;
            }
        }
    }
    else
    {
        for (int i = prime_count - 1; i >= 0; i--)
        {
            if (root == primes[i])
            {
                return 1;
            }
        }
    }

    return 0;
}

int is_square(unsigned long long int n)
{
    unsigned long long int r = (unsigned long long int)sqrt(n);
    return r * r == n;
}

int main()
{
    int t;
    unsigned long long n;

    // Adjust the size based on the maximum expected input
    initialize_sieve(1000000);

    scanf("%d", &t);

    while (t--)
    {
        scanf("%llu", &n);

        if (n < 4 || n == 1000000000000 || !is_square(n) || !T_Prime(n))
        {
            no;
        }
        else
        {
            yes;
        }
    }

    // Free allocated memory
    free(sieve);
    free(primes);

    return 0;
}
