#include <stdio.h>

int main()
{
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        (n % 4 == 0) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}