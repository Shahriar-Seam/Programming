#include <stdio.h>

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 2 == 1) {
            printf("NO\n");
        }
        else {
            printf("YES\n");

            for (i = 0; i < n / 2; i++) {
                printf("%c%c", 'A' + i, 'A' + i);
            }

            printf("\n");
        }
    }

    return 0;
}