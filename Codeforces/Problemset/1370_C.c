#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i;

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n == 1) {
            printf("FastestFinger\n");
        }
        else if (n == 2) {
            printf("Ashishgup\n");
        }
        else if (n % 2 == 1) {
            printf("Ashishgup\n");
        }
        else if ((int) log2(n) == log2(n)) {
            printf("FastestFinger\n");
        }
        else if (is_prime(n / 2)) {
            printf("FastestFinger\n");
        }
        else {
            printf("Ashishgup\n");
        }
    }

    return 0;
}
