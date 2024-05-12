// Write a recursive program to determine 
// whether a given integer is prime or not.

#include <stdio.h>
#include <math.h>

int is_prime(int n, int r, int i)
{
    if (n < 2) {
        return 0;
    }
    if (i > r) {
        return 1;
    }
    if (n % i == 0) {
        return 0;
    }

    return is_prime(n, r, i + 1);
}

int main()
{
    int n;

    scanf("%d", &n);

    if (is_prime(n, (int) sqrt(n), 2)) {
        printf("Prime\n");
    }
    else {
        printf("Not Prime\n");
    }

    return 0;
}