#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    set <int> s;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            cout << i + 1 << "\n";

            return;
        }

        if (i + 1 < n && (a[i] == a[i + 1] || b[i] == b[i + 1])) {
            cout << i + 1 << "\n";

            return;
        }

        if (s.find(a[i]) != s.end() || s.find(b[i]) != s.end()) {
            cout << i + 1 << "\n";

            return;
        }

        if (i + 1 < n) {
            s.insert(a[i + 1]);
            s.insert(b[i + 1]);
        }
    }

    cout << 0 << "\n";
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