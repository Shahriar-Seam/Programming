#include <stdio.h>
#include <stdlib.h>

#define max_size 90000000
int *primes;

void sieve()
{
    int i, j;

    primes = (int *)calloc(max_size + 1, sizeof(int));

    primes[2] = 2;
    primes[1] = 1;

    for (i = 4; i <= max_size; i += 2)
    {
        primes[i] = 2;
    }

    for (i = 3; i <= max_size; i += 2)
    {
        primes[i] = i;
    }

    for (i = 3; i * i <= max_size; i += 2)
    {
        if (primes[i] == i)
        {
            for (j = i * i; j <= max_size; j += i + i)
            {
                if (primes[j] == j) {
                    primes[j] = i;
                }
            }
        }
    }
}

int number_of_divisors(int n)
{
    int min_div, count, total_divisors = 1;

    while (primes[n] != 1) {
        min_div = primes[n];
        count = 1;

        while (primes[n] == min_div) {
            n /= min_div;

            count++;
        }

        total_divisors *= count;
    }

    if (n > 1) {
        total_divisors *= 2;
    }

    return total_divisors;
}

int main()
{
    int i, j, sum = 0;

    sieve();

    for (i = 10000; i < 13000; i++) {
        sum = (i * (i + 1)) / 2;

        if (number_of_divisors(sum) >= 500) {
            printf("%lld %lld %lld\n", i, sum, number_of_divisors(sum));
        }
    }

    return 0;
}