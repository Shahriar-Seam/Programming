#include <stdio.h>

int _min(int a, int b)
{
  return a < b ? a : b;
}

void solve()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    
    if ((a + b + c) % 2 == 1) {
        printf("-1\n");

        return;
    }

    printf("%d\n", _min((a + b + c) / 2, a + b));
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