#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, mn, mx;
    multiset <int> ms;

    cin >> n;

    vector <vector <int> > a(2, vector <int> (n));

    for (auto &it : a) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    ms.insert(a[0][0]);

    for (i = 0; i < n; i++) {
        ms.insert(a[1][i]);
    }

    mn = *ms.begin();
    mx = *(prev(ms.end()));

    for (i = 0; i < n - 1; i++) {
        ms.insert(a[0][i + 1]);
        ms.erase(ms.find(a[1][i]));

        mn = max(mn, *ms.begin());
        mx = min(mx, *(prev(ms.end())));
    }

    cout << mn * (n * 2 - mx + 1) << "\n";
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