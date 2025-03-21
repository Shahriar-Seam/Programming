#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j;
    vector <int> counter(10000, 0);

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    if (v[0] != 1) {
        cout << "NO\n";

        return;
    }

    counter[1] = 1;

    for (i = 1; i < n; i++) {
        if (counter[v[i]] > 0) {
            for (j = counter.size() - 1; j > 0; j--) {
                if (counter[j] > 0 && j + v[i] < counter.size()) {
                    counter[j + v[i]]++;
                }
            }
        }
        else {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";
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