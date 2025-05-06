#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, _max = 0, _min = 2e9, count = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        _max = max(_max, it);
        _min = min(_min, it);
    }

    for (auto it : v) {
        count += (it == _max);
    }

    if (_max - _min - 1 > k) {
        cout << "Jerry\n";
    }
    else if (_max - _min - 1 == k && count > 1) {
        cout << "Jerry\n";
    }
    else {
        if (accumulate(v.begin(), v.end(), 0LL) % 2 == 0) {
            cout << "Jerry\n";
        }
        else {
            cout << "Tom\n";
        }
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