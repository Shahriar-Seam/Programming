#include <stdio.h>
#include <limits.h>

int _max(int a, int b)
{
  return a > b ? a : b;
}

int mid(int a, int b, int c)
{
    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        return a;
    }
    if ((b >= a && b <= c) || (b >= c && b <= a)) {
        return b;
    }
    if ((c >= a && c <= b) || (c >= b && c <= a)) {
        return c;
    }
}

int _min(int a, int b)
{
  return a < b ? a : b;
}

void solve()
{
    int n, i, med = INT_MIN;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    if (n == 2) {
        printf("%d\n", _min(arr[0], arr[1]));

        return;
    }

    for (i = 1; i < n - 1; i++) {
        med = _max(med, mid(arr[i - 1], arr[i], arr[i + 1]));
    }

    printf("%d\n", med);
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