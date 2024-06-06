#include <stdio.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    if (n == 1) {
        printf("1");
    }
    else if (n < 4) {
        printf("NO SOLUTION\n");
    }
    else {
        for (i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }

        for (i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }
    }

    return 0;
}