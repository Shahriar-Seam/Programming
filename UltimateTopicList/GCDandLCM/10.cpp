#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b, g, i, range;

    cin >> n >> a >> b;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    g = __gcd(a, b);

    for (i = 0; i < n; i++) {
        v[i] %= g;
    }

    sort(v.begin(), v.end());

    range = v[n - 1] - v[0];

    for (i = 0; i < n - 1; i++) {
        range = min(range, v[i] + g - v[i + 1]);
    }

    cout << range << "\n";
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