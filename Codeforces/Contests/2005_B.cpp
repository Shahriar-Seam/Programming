#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, q, d;
    int ans;

    cin >> n >> m >> q;

    vector <int> v(m);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> d;

    if (d >= v[0] && d <= v[1]) {
        ans = min(abs((v[0] + v[1]) / 2 - v[0]), abs((v[0] + v[1]) / 2 - v[1]));
    }
    else if (d < v[0]) {
        ans = min(abs(d - v[0]), abs(d - (n - v[1] + d)));
    }
    else {
        ans = min(abs(d - v[1]), abs(d - (v[0] + n - d)));
    }

    cout << ans << "\n";
}

int main()
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