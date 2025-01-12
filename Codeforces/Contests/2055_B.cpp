#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, count = 0, min_dist = 1e9 + 9, req = 0, i;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            count++;
            req = b[i] - a[i];
        }
        else {
            min_dist = min(min_dist, a[i] - b[i]);
        }
    }

    cout << ((count <= 1 && min_dist >= req) ? "YES" : "NO") << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}