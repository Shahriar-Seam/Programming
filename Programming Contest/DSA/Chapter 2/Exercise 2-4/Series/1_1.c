#include <stdio.h>

int main()
{
    int n, i, sum1 = 0, sum2 = 0, sum3 = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum1 += i;
    }

    i = 0;

    while (i <= n) {
        sum2 += i;
        i++;
    }

    do
    {
        sum3 += n;
    } while (n--);

    printf("%d\n%d\n%d\n", sum1, sum2, sum3);
    

    return 0;
}