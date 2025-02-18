#include <bits/stdc++.h>

using namespace std;

const int sz = 2e5 + 5;
#define mod 998244353
vector <int> f(sz, 0);

void fill()
{
    int i;

    f[1] = 1;

    for (i = 2; i < sz; i++) {
        f[i] = (1LL * 2 * f[i - 1] + 1) % mod;
    }
}

void solve()
{
    int n, l, r, i, total = 0;

    cin >> n;

    vector <int> v(n), freq(n, 0), pref(n + 1, 0);
    deque <int> one, three;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (v[i] == 2) {
            freq[i] = 1;
        }

        if (v[i] == 1) {
            one.push_back(i);
        }
        else if (v[i] == 3) {
            three.push_back(i);
        }
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + freq[i];
    }

    for (auto it : one) {
        while (!three.empty() && three.front() < it) {
            three.pop_front();
        }

        for (auto it2 : three) {
            total = (0LL + total + f[pref[it2 + 1] - pref[it]]) % mod;
        }
    }

    cout << total << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}