#include <stdio.h>

int intlen(int n)
{
    int len = 0;

    while (n != 0) {
        len++;
        n /= 10;
    }

    return len;
}

int create_num(int n)
{
    int len = intlen(n), num = 1, i;

    for (i = 1; i < len; i++) {
        num *= 10;
    }

    return num;
}

int main()
{
    int t, n, ans, num;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        num = create_num(n);

        ans = n - num;

        printf("%d\n", ans);
    }

    return 0;
}