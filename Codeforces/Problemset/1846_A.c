#include <stdio.h>

int main()
{
    int t, n, a, b, ropes;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        ropes = 0;

        while (n--) {
            scanf("%d %d", &a, &b);

            if (a > b) {
                ropes++;
            }
        }

        printf("%d\n", ropes);
    }

    return 0;
}