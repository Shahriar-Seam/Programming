#include <stdio.h>
#include <limits.h>

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, i, first, last, k, temp, max = INT_MIN, min = INT_MAX;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        if (i == 0) {
            first = temp;
        }
        if (i == n - 1) {
            last = temp;
        }

        if (temp > max) {
            max = temp;
        }
        if (temp < min) {
            min = temp;
        }
    }

    if (k == 1) {
        printf("%d\n", min);
    }
    else if (k == 2) {
        printf("%d\n", _max(first, last));
    }
    else {
        printf("%d\n", max);
    }

    return 0;
}