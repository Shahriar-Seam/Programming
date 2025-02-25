#include <bits/stdc++.h>

using namespace std;

map <pair <int, int>, int> mp;

int t(int i, int j, int k)
{
    if (mp.find({i, j}) == mp.end()) {
        if (i == 1) {
            mp[{i, j}] = k;
        }
        else if (j == 1) {
            mp[{i, j}] = t(i - 1, j, k);
        }
        else if (j == i) {
            mp[{i, j}] = t(i - 1, j - 1, k);
        }
        else {
            mp[{i, j}] = t(i - 1, j - 1, k) ^ t(i - 1, j, k);
        }
    }

    return mp[{i, j}];
}

void solve()
{
    int n, k, j;

    mp.clear();

    cin >> n >> k;

    for (j = 1; j <= n; j++) {
        cout << t(n, j, k) << " ";
    }

    cout << "\n";
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