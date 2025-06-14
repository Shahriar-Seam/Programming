#include <bits/stdc++.h>

using namespace std;

struct item {
    int a, b, c;
};

void solve()
{
    int n, i;

    cin >> n;

    vector <item> v;

    v.push_back({1, 1, n});

    for (i = 2; i <= n; i++) {
        v.push_back({i, 1, n - i + 1});
        v.push_back({i, n - i + 2, n});
    }

    cout << v.size() << "\n";

    for (auto it : v) {
        cout << it.a << " " << it.b << " " << it.c << "\n";
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