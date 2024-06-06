#include <stdio.h>

int sum(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    int n, i, j, k;

    scanf("%d", &n);

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= n; k++) {
                if (sum(i, j, k) <= n) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }

    return 0;
}