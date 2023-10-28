#include <stdio.h>

int main()
{
    int t, n, num, sum;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        sum = 0;

        while (n--) {
            scanf("%d", &num);

            sum += (num * 2 - 2) / 2;
        }

        (sum % 2) == 1 ? printf("errorgorn\n") : printf("maomao90\n");
    }

    return 0;
}