#include <stdio.h>

int main()
{
    int n, d, i, temp, sum = 0, jokes = 0;

    scanf("%d %d", &n, &d);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        sum += temp;
    }

    sum += 10 * (n - 1);

    if (sum > d) {
        printf("-1\n");
    }
    else {
        printf("%d\n", 2 * (n - 1) + (d - sum) / 5);
    }

    return 0;
}