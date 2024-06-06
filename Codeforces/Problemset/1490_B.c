#include <stdio.h>

#define read(n) scanf("%d", (n))

void solve()
{
    int n, i, c0 = 0, c1 = 0, c2 = 0, count = 0;

    read(&n);

    int arr[n];

    for (i = 0; i < n; i++) {
        read(arr + i);

        arr[i] % 3 == 0 ? c0++ : arr[i] % 3 == 1 ? c1++ : c2++;
    }

    while (1) {
        if (c0 > c1) {
            c0--;
            c1++;
            count++;
        }
        else if (c1 > c2) {
            c1--;
            c2++;
            count++;
        }
        else if (c2 > c0) {
            c2--;
            c0++;
            count++;
        }
        else {
            break;
        }
    }

    printf("%d\n", count);
}

int main()
{
    int t;

    read(&t);

    while (t--) {
        solve();
    }

    return 0;
}