#include <stdio.h>

int main()
{
    int t, n, max;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 2 == 0) {
            max = n / 2;

            printf("%d\n", max);
        }
        else {
            max = (n + 1) / 2;
            printf("%d\n", max);
        }
    }

    return 0;
}