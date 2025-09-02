#include <bits/stdc++.h>

using namespace std;

int count(vector <pair <int, int> > &a, vector <int> &b, int m, int n)
{
    int cnt = 0, i, j;

    for (i = m, j = 0; i < n + m; i++, j++) {
        if (a[j].first > b[i % n]) {
            cnt++;
        }
    }

    return cnt;
}

void solve()
{
    int n, x, i, j;
    int l, r, m, cnt;

    cin >> n >> x;

    vector <pair <int, int> > a(n);
    vector <int> b(n), B(n);

    for (i = 0; i < n; i++) {
        cin >> a[i].first;

        a[i].second = i;
    }

    for (auto &it : b) {
        cin >> it;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (count(a, b, x, n) == x) {
        cout << "YES\n";

        for (i = x, j = 0; j < n; i++, j++) {
            B[a[j].second] = b[i % n];
        }

        for (auto &it : B) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
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