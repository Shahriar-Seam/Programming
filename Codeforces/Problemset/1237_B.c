#include <stdio.h>
#include <stdint.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int32_t main()
{
    int n, i, count = 0, last = 0;

    scanf("%d", &n);

    int a[n], b[n], indices[n + 1];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", b + i);

        indices[b[i]] = i;
    }

    for (i = 0; i < n; i++) {
        if (indices[a[i]] < last) {
            count++;
        }

        last = max(last, indices[a[i]]);
    }

    printf("%d\n", count);

    return 0;
}