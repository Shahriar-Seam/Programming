#include <stdio.h>

int main()
{
    int n, i, j, k = 1, sum = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            sum += k++;
        }
    }

    printf("%d\n", sum);

    return 0;
}