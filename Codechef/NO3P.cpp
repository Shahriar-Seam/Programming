#include <bits/stdc++.h>

using namespace std;

bool good(vector <int> &v, int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++) {
        sum += v[i];

        if (sum % 3 == 0) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, i, r;

    cin >> n;

    vector <int> v(n), pref(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (good(v, n)) {
        cout << "YES\n";

        return;
    }

    for (i = 0; i < n; i++) {
        pref[i] = v[i] + (i > 0 ? pref[i - 1] : 0);
    }

    for (i = n - 1; i >= 0; i--) {
        if (pref[i] % 3 == 0) {
            r = i;

            break;
        }
    }

    for (i = r + 1; i <= min(n, r + 50); i++) {
        vector <int> temp = v;

        reverse(temp.begin(), temp.begin() + i);

        if (good(temp, n)) {
            cout << "YES\n";

            return;
        }
    }

    cout << "NO\n";
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