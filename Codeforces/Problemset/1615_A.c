#include <stdio.h>

int main()
{
    int t, tt, i, n, sum;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &tt);

        sum = 0;

        for (i = 0; i < tt; i++) {
            scanf("%d", &n);

            sum += n;
        }

        if (sum % tt == 0) {
            printf("0\n");
        }
        else {
            printf("1\n");
        }
    }

    return 0;
}