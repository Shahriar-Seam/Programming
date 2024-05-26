#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max_size = 1000005;
int *marked;
int *primes;

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

void sieve()
{
    int i, j;

    marked = (int *) calloc(max_size, sizeof(int));
    primes = (int *) calloc(78500, sizeof(int));
    marked[0] = 1;

    for (i = 1; i < max_size; i += 2) {
        marked[i] = i;
    }
    
    for (i = 2; i < max_size; i += 2) {
        marked[i] = 2;
    }

    for (i = 3; i * i <= max_size; i += 2) {
        if (marked[i] == i) {
            for (j = i * i; j <= max_size; j += i + i) {
                if (marked[j] == j) {
                    marked[j] = i;
                }
            }
        }
    }

    for (i = 2, j = 0; i < max_size; i++) {
        if (marked[i] == i) {
            primes[j++] = i;
        }
    }
}

int count_divisors(long long int n)
{
    int i, count = 1, cnt = 0;
    long long int p;

    for (i = 0; i < 78500; i++) {
        if (n == 1) {
            break;
        }

        if (n % primes[i] == 0) {
            p = primes[i];
            cnt = 0;

            while (n % p == 0) {
                n /= p;

                cnt++;
            }

            count *= (cnt + 1);
        }
    }

    return count;
}

void solve()
{
    int n, i, f = 1;
    long long int num;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), compare);

    num = 1LL * arr[0] * arr[n - 1];

    for (i = 0; i <= n / 2; i++) {
        if (1LL * arr[i] * arr[n - i - 1] != num) {
            f = 0;
        }
    }

    if ((f == 1) && (count_divisors(num) == n + 2)) {
        printf("%lld\n", num);
    }
    else {
        printf("-1\n");
    }
}

int main()
{
    sieve();
    int count = 0;

    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}