#include <stdio.h>

int _count(int arr[], int n, int h, int _h)
{
    int i, sum = 0;

    if (n == 1) {
        return h + 2;
    }

    for (i = 0; i < n; i++) {
        if (_h > arr[i]) {
            sum += _h - arr[i];
        }
    }

    if (sum > h) {
        return _h;
    }
    else {
        return 0;
    }
}

int main()
{
    int t, T, n, i;

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &n, &t);

        int arr[n];

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int c = 0;
        int _h = t / n;

        while (!c) {
            c = _count(arr, n, t, _h++);
        }

        printf("%d\n", c - 1);
    }

    return 0;
}