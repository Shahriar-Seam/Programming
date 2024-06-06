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
    int num, temp, prime = 0, non_prime = 0;

    scanf("%d", &num);

    while (num > 0) {
        temp = num % 10;

        if (is_prime(temp) == 1) {
            prime += temp;
        }
        else {
            non_prime += temp;
        }

        num /= 10;
    }

    if (prime > non_prime) {
        printf("Prime\n");
    }
    else {
        printf("Non Prime\n");
    }

    return 0;
}