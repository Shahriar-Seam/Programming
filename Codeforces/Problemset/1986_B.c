#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

int _max(int count, ...)
{
    int i, max_value = INT_MIN;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        max_value = max(max_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return max_value;
}

void solve()
{
    int n, m, i, j;

    scanf("%d %d", &n, &m);

    int matrix[n][m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
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