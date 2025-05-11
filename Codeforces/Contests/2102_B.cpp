#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, first, index;

    cin >> n;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        v[i] = abs(v[i]);

        if (i == 0) {
            first = v[i];
        }
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (v[i] == first) {
            index = i;
        }
    }

    int mid = (n - 1) / 2;

    if (index <= mid) {
        cout << "YES\n";
    }
    else {
        if ((n % 2 == 0) && (index == mid + 1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
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