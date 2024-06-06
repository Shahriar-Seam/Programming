#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i, root = sqrt(n);

    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0) {
        return 0;
    }

    for (i = 3; i <= root; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n, i, x, sum_p = 0, sum_np = 0;

    scanf("%d", &n);

    while (n != 0) {
        x = n % 10;

        if (is_prime(x)) {
            sum_p += x;
        }
        else {
            sum_np += x;
        }

        n /= 10;
    }

    printf("Sum of prime digits: %d\n", sum_p);
    printf("Sum of non-prime digits: %d\n", sum_np);

    return 0;
}