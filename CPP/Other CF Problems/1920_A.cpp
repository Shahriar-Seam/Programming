#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, x;
    int _min = 0, _max = 2e9, count = 0;
    set <int> s;

    cin >> n;

    while (n--) {
        cin >> a >> x;

        if (a == 1) {
            _min = max(_min, x);
        }
        else if (a == 2) {
            _max = min(_max, x);
        }
        else {
            s.insert(x);
        }
    }

    count = _max - _min + 1;

    for (auto it : s) {
        if (it >= _min && it <= _max) {
            count--;
        }
    }

    cout << max(0, count) << "\n";
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