#include <stdio.h>

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n < 2) {
            printf("-1");
        }
        else {
            printf("2");

            for (i = 1; i < n; i++) {
                printf("3");
            }
        }

        printf("\n");
    }

    return 0;
}