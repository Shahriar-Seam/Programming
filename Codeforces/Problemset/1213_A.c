#include <stdio.h>

int main()
{
    int n, count = 0, i, temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        count += temp % 2;
    }

    printf("%d", count > n - count ? n - count : count);

    return 0;
}