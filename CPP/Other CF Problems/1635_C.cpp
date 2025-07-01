#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i;
    int x, y, z, cnt = 0;

    cin >> n;

    vector <int> v(n);
    string ops;

    for (auto &it : v) {
        cin >> it;
    }

    if (v[n - 1] < v[n - 2]) {
        cout << "-1\n";

        return;
    }

    if (v[n - 1] < 0) {
        if (is_sorted(v.begin(), v.end())) {
            cout << 0 << "\n";
        }
        else {
            cout << -1 << "\n";
        }

        return;
    }

    for (i = n - 3, z = n - 1; i >= 0; i--) {
        y = i + 1;
        x = i;

        while (v[i] > v[i + 1]) {
            v[i] = v[y] - v[z];

            cnt++;

            ops += string(to_string(x + 1) + " " + to_string(y + 1) + " " + to_string(z + 1) + "\n");
        }
    }

    cout << cnt << "\n";

    cout << ops;
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