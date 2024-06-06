#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= 10; i++) {
            printf("%2d x %2d = %3d\n", j, i, j * i);
        }

        printf("-------------\n");
    }

    return 0;
}