#include <stdio.h>

int c = 0;

int fun(int n)
{
    int x = 1, k;

    c++;

    if (n == 1) {
        return x;
    }
    
    for (k = 1; k < n; k++) {
        x = x + fun(k) * fun(n - k) + fun(n - k);
    }

    return x;
}

int main()
{
    int n, x;

    scanf("%d", &n);

    x = fun(n);

    printf("%d %d\n", x, c);

    return 0;
}