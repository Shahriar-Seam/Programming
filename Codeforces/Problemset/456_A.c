#include <stdio.h>

int main()
{
    int t, a, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &a, &b);

        if (a != b) {
            printf("Happy Alex");

            return 0;
        }
    }

    printf("Poor Alex");

    return 0;
}