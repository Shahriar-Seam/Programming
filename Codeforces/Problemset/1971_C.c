/**
 *    author:  Anonymous_HF
 *    created: 14/05/2024 12:16:53
**/

#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

void solve()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b) {
        swap(&a, &b);
    }

    if (c > d) {
        swap(&c, &d);
    }

    if ((c > a && c < b) && (d < a || d > b)) {
        puts("YES");
    }
    else if ((a > c && a < d) && (b < c || b > d)) {
        puts("YES");
    }
    else {
        puts("NO");
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