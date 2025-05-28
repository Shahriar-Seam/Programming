#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, count = 0, sz = 0;
    
    cin >> n;
    
    vector <int> v(n);
    
    for (auto &it : v) {
        cin >> it;

        sz = max(sz, it);
    }

    vector <bool> counter(int(sz + 5), false);
    vector <bool> bamboo(int(sz + 5), false);

    for (i = 0; i < n; i++) {
        if (bamboo[v[i] - 1]) {
            counter[v[i]] = true;
            counter[v[i] - 1] = true;
        }

        bamboo[v[i]] = true;
    }

    count = accumulate(counter.begin(), counter.end(), 0);

    cout << accumulate(bamboo.begin(), bamboo.end(), 0) - (count / 2) << "\n";
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