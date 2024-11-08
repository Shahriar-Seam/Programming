#include <bits/stdc++.h>

using namespace std;

int a, b, c;

bool ch(int a1, int b1, int c1)
{
    return a == a1 && b == b1 && c == c1;
}

void solve()
{
    cin >> a >> b >> c;

    if (a < b) {
        swap(a, b);
    }
    if (b < c) {
        swap(b, c);
    }
    if (a < b) {
        swap(a, b);
    }

    if (ch(6, 3, 0) || ch(6, 1, 1) || ch(4, 3, 1) || ch(4, 4, 0) || ch(4, 2, 1) || ch(3, 3, 3) || ch(2, 2, 2)) {
        cout << "perfectus\n";

        return;
    }
    else {
        cout << "invalidum\n";

        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}