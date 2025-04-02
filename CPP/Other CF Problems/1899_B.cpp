#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1.5e5 + 5;
vector <vector <int> > divisors(sz, vector <int> ());

void get_divisors()
{
    int i, j;

    for (i = 2; i < sz; i++) {
        for (j = i + i; j < sz; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve()
{
    int n, i, j, diff = 0, _min = 2e18, _max = 0;

    cin >> n;

    vector <int> v(n), pref(n + 1, 0);

    for (auto &it : v) {
        cin >> it;

        _min = min(_min, it);
        _max = max(_max, it);
    }

    diff = _max - _min;

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (auto k : divisors[n]) {
        _min = 2e18;
        _max = 0;

        for (i = k; i <= n; i += k) {
            _max = max(_max, pref[i] - pref[i - k]);
            _min = min(_min, pref[i] - pref[i - k]);
        }

        diff = max(diff, _max - _min);
    }

    cout << diff << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_divisors();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}