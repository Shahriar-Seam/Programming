#include <stdio.h>

int seq[130] = {};

int find(int x, int size)
{
    int i;

    for (i = size - 2; i >= 0; i--) {
        if (seq[i] == x) {
            return size - i - 1;
        }
    }

    return -1;
}

void sequence()
{
    int i, x, k;

    for (i = 1; i < 130; ) {
        x = seq[i - 1];

        k = find(x, i);

        if (k != -1) {
            seq[i++] = k;
        }
        else {
            seq[i++] = 0;
        }
    }
}

int count(int x)
{
    int i, cnt = 0;

    for (i = 0; i < x; i++) {
        cnt += (seq[i] == seq[x - 1]);
    }

    return cnt;
}

void solve()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", count(n));
}

int main()
{
    sequence();

    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}