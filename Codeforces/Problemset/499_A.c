#include <stdio.h>

int main()
{
    int n, x, i, l, r, sum = 1, mins = 0;

    scanf("%d %d", &n, &x);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);

        while (sum + x <= l) {
            sum += x;
        }

        mins += r - sum + 1;

        sum = r + 1;
    }

    printf("%d\n", mins);

    return 0;
}