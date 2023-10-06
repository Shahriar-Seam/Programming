#include <stdio.h>

int main()
{
    int t, n, num, min, max;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &num);

        min = max = num;

        for (int i = 1; i < n; i++) {
            scanf("%d", &num);

            min = (num < min) ? num: min;
            max = (num > max) ? num: max;
        }

        printf("%d\n", max - min);
    }

    return 0;
}