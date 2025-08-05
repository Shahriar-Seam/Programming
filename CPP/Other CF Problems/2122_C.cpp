#include <bits/stdc++.h>

using namespace std;

struct item {
    int x, y, i;
};

void solve()
{
    int n, i;

    cin >> n;

    vector <item> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;

        v[i].i = i + 1;
    }

    sort(v.begin(), v.end(), [&] (item i, item j) {
        return i.x < j.x;
    });

    sort(v.begin(), v.begin() + n / 2, [&] (item i, item j) {
        return i.y < j.y;
    });

    sort(v.begin() + n / 2, v.end(), [&] (item i, item j) {
        return i.y < j.y;
    });

    for (i = 0; i < n / 2; i++) {
        cout << v[i].i << " " << v[n - i - 1].i << "\n";
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