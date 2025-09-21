#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, a = 0, b = 0, f = 0;
    map <int, int> mp_t;
    map <int, int, greater <> > mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp_t[it]++;
    }

    for (auto &it : mp_t) {
        mp[it.second] = it.first;
    }

    for (auto &it : mp) {
        if (f % 2 == 0) {
            if (it.second % 2 == 1) {
                a += it.first * ((it.second + 1) / 2);
                b += it.first * (it.second / 2);

                f = 1;
            }
            else {
                a += it.first * (it.second / 2);
                b += it.first * (it.second / 2);
            }
        }
        else {
            if (it.second % 2 == 1) {
                a += it.first * (it.second / 2);
                b += it.first * ((it.second + 1) / 2);

                f = 0;
            }
            else {
                a += it.first * (it.second / 2);
                b += it.first * (it.second / 2);
            }
        }
    }

    cout << a << " " << b << "\n";
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