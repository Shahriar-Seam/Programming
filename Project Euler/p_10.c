#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max_size 2000002
bool *marked;

void sieve()
{
    int i, j;

    marked = (bool *)calloc(max_size + 1, sizeof(bool));

    for (i = 4; i <= max_size; i += 2)
    {
        marked[i] = true;
    }

    for (i = 3; i * i <= max_size; i += 2)
    {
        if (marked[i] == false)
        {
            for (j = i * i; j <= max_size; j += i + i)
            {
                marked[j] = true;
            }
        }
    }
}

int main()
{
    int i;
    long long int sum = 2;

    sieve();

    for (i = 3; i < max_size; i += 2) {
        if (marked[i] == false) {
            sum += 1LL * i;

            // printf("%d\n", i);
        }
    }

    printf("%lld\n", sum);
}