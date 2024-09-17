#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int l, r, a, x, temp;

    scanf("%d %d %d", &l, &r, &a);

    x = r / a + r % a;
    temp = (r / a) * a - 1;

    if(temp >= l) {
        x = max(x, temp / a + temp % a);
    }

    printf("%d\n", x);
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