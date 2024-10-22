#include <stdio.h>

int lucky_digits(int n)
{
    int count = 0;

    while (n > 0) {
        count += ((n % 10 == 7) || (n % 10 == 4));

        n /= 10;
    }

    return count;
}

int main()
{
    int n, k, count = 0, i, temp;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        count += (lucky_digits(temp) <= k);
    }

    printf("%d\n", count);

    return 0;
}