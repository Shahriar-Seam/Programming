#include <stdio.h>
#include <stdlib.h>

#define size 1000005
int *primes;

void sieve()
{
    int i, j;

    primes = (int *) malloc(sizeof(int) * size);

    primes[0] = 1;

    for (i = 1; i < size; i += 2) {
        primes[i] = i;
    }

    for (i = 2; i < size; i += 2) {
        primes[i] = 2;
    }

    for (i = 3; i * i < size; i++) {
        if (primes[i] == i) {
            for (j = i; j < size; j += i) {
                // if (primes[j] == j) {
                    primes[j] = i;
                // }
            }
        }
    }
}

void solve()
{
    int n, i;
    long long k = 0;
    
    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            k += 1LL * primes[i];

            printf("%d ", i);
        }
    }

    printf("\nk = %lld\n", k);
}

int main()
{
    sieve();

    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}