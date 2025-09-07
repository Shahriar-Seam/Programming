#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, a_b;

    cin >> a >> b;

    if (b % 2 == 0) {
        a_b = a * b / 2 + 2;
    }
    else {
        a_b = a * b + 1;
    }

    if (!(a_b & 1)) {
        cout << a_b << "\n";
    }
    else {
        cout << "-1\n";
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