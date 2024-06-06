#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_size 1000000
bool *primes;

void sieve()
{
    int i, j;

    primes = (bool *) calloc(max_size, sizeof(bool));

    for (i = 4; i < max_size; i += 2) {
        primes[i] = true;
    }

    for (i = 3; i * i < max_size; i += 2) {
        if (primes[i] == false) {
            for (j = i * i; j < max_size; j += i + i) {
                primes[j] = true;
            }
        }
    }
}

void circle(int *n)
{
    int temp = *n, len = 10;

    while (temp / 10 > 0) {
        temp /= 10;
        len *= 10;
    }

    *n = (*n * 10 + temp) % len;
}

int is_circular(int n)
{
    int temp = n;

    if (primes[temp] == false) {
        circle(&temp);

        if (primes[temp] == true) {
            return false;
        }

        while (n != temp) {
            if (primes[temp] == true) {
                return false;
            }
            else {
                circle(&temp);
            }
        }

        return true;
    }
    else {
        return false;
    }
}

int main()
{
    sieve();
    int i, j, temp, count = 0;

    for (i = 2; i < 100; i++) {
        temp = i;

        if (is_circular(i) == true) {
            // printf("%d\n", i);

            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}