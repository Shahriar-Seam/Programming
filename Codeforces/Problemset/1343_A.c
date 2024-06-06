#include <stdio.h>

int main()
{
    int t, n, num, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        num = 3;

        if (n % num == 0) {
            printf("%d\n", n / num);
        }
        else {
            for (i = 2; i < n; i++) {
                num += 1 << i;

                if (n % num == 0) {
                    printf("%d\n", n / num);
                    break;
                }
            }
        }
    }

    return 0;
}