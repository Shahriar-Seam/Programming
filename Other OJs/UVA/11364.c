#include <stdio.h>
#include <limits.h>

int main()
{
    int t, n, temp, max, min;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        max = INT_MIN;
        min = INT_MAX;

        while (n--) {
            scanf("%d", &temp);

            if (temp > max) {
                max = temp;
            }
            if (temp < min) {
                min = temp;
            }
        }

        printf("%d\n", 2 * (max - min));
    }

    return 0;
}