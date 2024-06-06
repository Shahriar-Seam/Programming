#include <stdio.h>
#include <math.h>

int main()
{
    int t, n, x, f;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &x);

        if (n <= 2) {
            printf("1\n");
        }
        else {
            printf("%d\n", ((n - 3) / x) + 2);
        }
    }

    return 0;
}