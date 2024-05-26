#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int is_prime(int n)
{
    int i;

    if (n == 2) {
        return 0;
    }

    if (n % 2 == 0) {
        return 0;
    }

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n, i, count = 0;
    long long int product = 1;
    int arr[100005] = {};

    scanf("%d", &n);

    // Wilson's theorem
    // (p - 1)! = -1 (mod p) = p - 1 (mod p)
    if (is_prime(n) == 1) {
        printf("%d\n", n - 2);

        for (i = 1; i < n - 1; i++) {
            printf("%d ", i);
        }
    }
    else {
        for (i = 1; i < n; i++) {
            if (gcd(i, n) == 1) {
                arr[i] = 1;

                product *= i;
                product %= n;

                count++;
            }
        }

        if (product == 1) {
            printf("%d\n", count);

            for (i = 1; i < n; i++) {
                if (arr[i] == 1) {
                    printf("%d ", i);
                }
            }
        }
        else {
            printf("%d\n", count - 1);

            for (i = 1; i < n; i++) {
                if ((arr[i] == 1) && (product != i)) {
                    printf("%d ", i);
                }
            }
        }
    }

    return 0;
}