#include <stdio.h>

int main()
{
    int t, n, count = 0, sum = 0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        sum += n;

        if (sum > 365) {
            break;
        }

        if (n >= 11) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}