#include <stdio.h>
#include <math.h>

int is_prime(long long int n)
{
    long long int r1 = sqrt(n);
    int r2 = sqrt(r1);
    int i;

    if (n == 1) {
        return 0;
    }
    else if (r1 % 2 == 0 && r1 != 2) {
        return 0;
    }
    else if (r1 * r1 == n) {
        for (i = 3; i <= r2 + 1; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }

        return 1;
    }

    else {
        return 0;
    }
}

int main()
{
    int t;
    long long int n;

    scanf("%d", &t);

    while (t--) {
        scanf("%lld", &n);

        if (is_prime(n)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}