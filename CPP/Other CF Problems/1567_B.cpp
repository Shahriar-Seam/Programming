#include <bits/stdc++.h>

using namespace std;

// xor from 1 to n
int consecutive_xor(int n)
{
    if (n % 4 == 0) {
        return n;
    }
    else if (n % 4 == 1) {
        return 1;
    }
    else if (n % 4 == 2) {
        return n + 1;
    }
    else {
        return 0;
    }
}

// a ^ b == c
// b = ?
int anti_xor(int a, int c)
{
    int b = 0, i;
    bool p, q;

    for (i = 30; i >= 0; i--) {
        p = a & (1 << i);
        q = c & (1 << i);

        if ((!p && q) || (p && !q)) {
            b |= (1 << i);
        }
    }

    return b;
}

void solve()
{
    int a, b;

    cin >> a >> b;

    if (consecutive_xor(a - 1) == b) {
        cout << a << "\n";
    }
    else if (anti_xor(consecutive_xor(a - 1), b) == a) {
        cout << a + 2 << "\n";
    }
    else {
        cout << a + 1 << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}