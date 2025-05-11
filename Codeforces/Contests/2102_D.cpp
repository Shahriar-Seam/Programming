#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n), indices(n + 1, -1), p(n + 2, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        indices[v[i]] = i + 1;
    }

    for (i = 1; i <= n; i++) {
        if (i % 2 == indices[i] % 2) {
            p[i] = i;
        }
        else {
            p[i] = i + 1;
            p[i + 1] = i;

            i++;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << p[i] << " ";
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