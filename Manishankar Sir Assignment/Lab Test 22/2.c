#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int root = sqrt(n), i;

    if (n < 2) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else if (n % 2 == 0) {
        return 0;
    }

    for (i = 3; i <= root; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int count_primes(int *arr, int i) {
    if (i == 20) {
        return 0;
    }
    else if (is_prime(arr[i])) {
        return 1 + count_primes(arr, i + 1);
    }
    else {
        return count_primes(arr, i + 1);
    }
}

int main()
{
    int arr[20], i, count;

    for (i = 0; i < 20; i++) {
        scanf("%d", &arr[i]);
    }

    count = count_primes(arr, 0);

    printf("Number of primes = %d\n", count);

    return 0;
}