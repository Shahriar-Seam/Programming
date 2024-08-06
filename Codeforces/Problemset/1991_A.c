#include <stdio.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
    int n, max_val = 0, i;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n; i += 2) {
        max_val = max(max_val, arr[i]);
    }

    printf("%d\n", max_val);
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