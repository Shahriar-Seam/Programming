#include <stdio.h>

void solve()
{
    int n, i, l, r, temp;

    scanf("%d", &n);

    int arr1[n], arr2[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr1 + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", arr2 + i); 
    }

    for (i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            l = i;

            break;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        if (arr1[i] != arr2[i]) {
            r = i;

            break;
        }
    }

    while (l > 0) {
        if (arr2[l - 1] > arr2[l]) {
            break;
        }

        l--;
    }

    while (r < n - 1) {
        if (arr2[r + 1] < arr2[r]) {
            break;
        }

        r++;
    }

    printf("%d %d\n", l + 1, r + 1);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}