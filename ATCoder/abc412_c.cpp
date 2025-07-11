#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, l, r, i, j, count = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    l = v[0];
    r = v.back();

    if (r <= l) {
        cout << "2\n";

        return;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (v[i] == r) {
            r = i;

            break;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        if (v[i] == l) {
            l = i;

            break;
        }
    }

    for (i = l; i < r; count++) {
        j = i + 1;

        while (j <= r) {
            if (v[j] <= 2 * v[i]) {
                j++;
            }
            else {
                break;
            }
        }

        if (j == i + 1) {
            cout << "-1\n";

            return;
        }

        i = j - 1;
    }

    cout << count << "\n";
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