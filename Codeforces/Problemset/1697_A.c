#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int t, n, m, temp, sum;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        sum = 0;

        while (n--) {
            scanf("%d", &temp);

            sum += temp;
        }

        printf("%d\n", max(0, sum - m));
    }

    return 0;
}