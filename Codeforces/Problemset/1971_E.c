#include <stdio.h>

int position(int *arr, int l, int r, int key)
{
    int mid;

    while (l <= r) {
        mid = l + r / 2;

        if (key > arr[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return arr[r] == key ? mid: mid - 1;
}

void solve()
{
    int n, k, q, d, i, pos;
    int mins;

    scanf("%d %d %d", &n, &k, &q);

    int signs[k + 1];
    int minutes[k + 1];

    signs[0] = minutes[0] = 0;

    for (i = 1; i <= k; i++) {
        scanf("%d", signs + i);
    }

    for (i = 1; i <= k; i++) {
        scanf("%d", minutes + i);
    }

    while (q--) {
        scanf("%d", &d);

        pos = position(signs, 1, k, d);

        if (signs[pos] == d) {
            mins = minutes[pos];
        }
        else {
            mins = minutes[pos] + (d - signs[pos]) * 1.0 * (minutes[pos + 1] - minutes[pos]) / (signs[pos + 1] - signs[pos]);
        }

        printf("%d ", mins);
    }

    printf("\n");
}

int main()
{
    int t;
    char s[1000000];

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}