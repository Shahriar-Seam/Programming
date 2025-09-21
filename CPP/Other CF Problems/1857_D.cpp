#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> a(n), b(n), s;
    vector <pair <int, int> > v(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v[i] = {a[i] - b[i], i + 1};
    }

    sort(v.begin(), v.end(), greater <> ());

    s.push_back(v[0].second);

    for (i = 1; i < n; i++) {
        if (v[i].first == v[0].first) {
            s.push_back(v[i].second);
        }
    }

    sort(s.begin(), s.end());

    cout << s.size() << "\n";

    for (auto &it : s) {
        cout << it << " ";
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