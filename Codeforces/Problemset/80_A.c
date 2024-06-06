#include <stdio.h>

int arr[51];
int prime_nums[15];

void sieve()
{
    int i, j;

    for (i = 2; i <= 50; i++) {
        arr[i] = i;
    }

    for (i = 2; i <= 50; i++) {
        if (arr[i] != 0) {
            for (j = i * i; j <= 50; j += i) {
                if (arr[j] % i == 0) {
                    arr[j] = 0;
                }
            }
        }
    }
}

void primes()
{
    int i, j;

    for (i = 0, j = 0; i < 51; i++) {
        if (arr[i] != 0) {
            prime_nums[j] = arr[i];
            j++;
        }
    }
}

int main()
{
    int n, m, i, index;

    sieve();
    primes();

    scanf("%d %d", &n, &m);

    for (i = 0; i < 15; i++) {
        if (prime_nums[i] == n) {
            index = i;
            break;
        }
    }

    (prime_nums[index + 1] == m) ? printf("YES") : printf("NO");

    return 0;
}