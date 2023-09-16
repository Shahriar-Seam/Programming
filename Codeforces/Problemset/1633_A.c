#include <stdio.h>

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 7 == 0) {
            printf("%d\n", n);
        }
        else {
            n = (n / 10) * 10;

            for (i = 0; i < 10; i++) {
                n++;

                if (n % 7 == 0) {
                    printf("%d\n", n);
                    break;
                }
            }
        }
    }

    return 0;
}