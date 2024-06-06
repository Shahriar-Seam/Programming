#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i, root = sqrt(n), prime = 1;

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
    int i, n, root;

    printf("Enter a number: ");
    scanf("%d", &n);

    root = sqrt(n);

    printf("The prime factors of the number is: ");
    for (i = 2; i <= n; i++) {
        if (is_prime(i) && n % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}