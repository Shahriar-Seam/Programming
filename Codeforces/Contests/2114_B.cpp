#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, one = 0, zero = 0;
    string s;

    cin >> n >> k >> s;

    for (auto c : s) {
        one += (c == '1');
    }

    zero = n - one;

    int _min = abs(one - zero) / 2;
    int _max = _min + min(zero, one);

    if (_min <= k && k <= _max && (k % 2 == _min % 2)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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