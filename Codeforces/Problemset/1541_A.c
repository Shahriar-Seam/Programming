#include <stdio.h>

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 2 == 0) {
            for (i = 1; i < n; i += 2) {
                printf("%d %d ", i + 1, i);
            }
        }

        else {
            printf("3 1 2 ");

            for (i = 4; i < n; i += 2) {
                printf("%d %d ", i + 1, i);
            }
        }

        printf("\n");
    }

    return 0;
}