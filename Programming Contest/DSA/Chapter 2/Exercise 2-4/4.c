#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i, root = sqrt(n);

    if (n == 2) {
        return 1;
    }
    else if (n < 2 || (n % 2 == 0)) {
        return 0;
    }
    else {
        for (i = 3; i <= root; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int n;

    scanf("%d", &n);

    is_prime(n) ? printf("YES\n") : printf("NO\n");

    return 0;
}