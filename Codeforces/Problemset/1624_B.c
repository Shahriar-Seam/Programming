/**
 *    author:  Anonymous_HF
 *    created: 09/05/2024 00:40:33
**/

#include <stdio.h>

#define yes puts("YES")
#define no puts("NO")

void solve()
{
    int a, b, c;
    static int cnt = 0;

    scanf("%d %d %d", &a, &b, &c);

    cnt++;

    if ((a + 2 * (b - a)) % c == 0 && (a + 2 * (b - a)) != 0) {
        yes;
    }
    else if ((c + 2 * (b - c)) % a == 0 && (c + 2 * (b - c)) != 0) {
        yes;
    }
    else if ((c - a) % 2 == 0 && ((c - a) / 2) % b == 0) {
        yes;
    }
    else {
        no;
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