#include <stdio.h>

int main()
{
    int t, n, count, possible;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        count = 0;
        possible = 1;

        while (1) {
            if ((n % 6 == 2) || (n % 6 == 4) || (n == 5)) {
                printf("-1\n");
                possible = 0;
                break;
            }
            if (n == 1) {
                break;
            }

            if (n % 6 == 0) {
                n = n / 6;
            }
            else {
                n = n * 2;
            }

            count++;
        }

        if (possible) {
            printf("%d\n", count);
        }
    }

    return 0;
}