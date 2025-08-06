#include <bits/stdc++.h>

using namespace std;

struct item {
    string n;
    int y;

    bool operator < (item it) {
        return y > it.y;
    }
};

void solve()
{
    int n;

    cin >> n;

    vector <item> v(n);

    for (auto &it : v) {
        cin >> it.n >> it.y;
    }

    sort(v.begin(), v.end());

    for (auto &it : v) {
        cout << it.n << "\n";
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