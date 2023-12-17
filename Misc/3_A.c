#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i, root = sqrt(n);

    if (n < 2) {
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
    int num, i;

    scanf("%d", &num);

    for (i = 2; i <= num; i++) {
        if (num % i == 0) {
            if (is_prime(i) == 1) {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}