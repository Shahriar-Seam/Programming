#include <bits/stdc++.h>

using namespace std;

// https://stackoverflow.com/questions/29388711/how-to-get-the-bit-length-of-an-integer-in-c
// C++ 20
int bit_length(unsigned n)
{
    return 8 * sizeof(n) - __countl_zero(n);
}

void solve()
{
    int x, y, k;

    cin >> x >> y;

    if (x == y) {
        k = -1;
    }
    else {
        k = (1 << bit_length(max(x, y))) - max(x, y);
    }

    cout << k << "\n";
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