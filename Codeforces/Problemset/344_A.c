#include <stdio.h>

int main()
{
    int n, a, b, count = 1;

    scanf("%d", &n);
    scanf("%d", &b);

    int t = n - 1;

    while (t--) {
        scanf("%d", &a);

        if (a != b) {
            count++;
        }

        b = a;
    }

    printf("%d", count);

    return 0;
}