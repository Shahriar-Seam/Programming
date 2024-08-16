#include <stdio.h>

int primes[168] = {};
int count[1005] = {};

void sieve()
{
    int i, j;
    int marked[1000] = {};

    for (i = 3; i < 1000; i += 2) {
        if (marked[i] == 0) {
            for (j = i * i; j < 1000; j += i + i) {
                marked[j] = 1;
            }
        }
    }

    primes[0] = 2;

    for (i = 3, j = 1; i < 1000; i += 2) {
        if (marked[i] == 0) {
            primes[j++] = i;
        }
    }
}

int is_prime(int n)
{
    int low = 0, high = 168, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (primes[mid] == n) {
            return 1;
        }
        else if (primes[mid] > n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return 0;
}

int fill_count()
{
    int i;

    for (i = 1; i < 168; i++) {
        if ((primes[i] + primes[i - 1] + 1 <= 1000) && is_prime(primes[i] + primes[i - 1] + 1)) {
            count[primes[i] + primes[i - 1] + 1]++;
        }
    }

    for (i = 1; i < 1005; i++) {
        count[i] += count[i - 1];
    }
}

int main()
{
    sieve();
    fill_count();

    int n, k;

    scanf("%d %d", &n, &k);

    puts(count[n] >= k ? "YES" : "NO");

    return 0;
}