#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 1e9, i, j;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    // already even
    if ((v[0] + v[n - 1]) % 2 == 0) {
        cout << "0\n";
    }
    else {
        for (i = 0; i < n; i++) {
            for (j = n - 1; j >= i; j--) {
                if ((v[i] + v[j]) % 2 == 0) {
                    count = min(count, i + (n - 1 - j));
                }
            }
        }

        cout << count << "\n";
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