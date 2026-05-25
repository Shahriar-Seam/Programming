#include <bits/stdc++.h>

using namespace std;

bool possible(int x, int n, vector <int> &a, vector <int> &b)
{
    int l = 0, s = 0, i, last = 1;

    for (i = 0; i < n; i++) {
        if (a[i] >= x && b[i] >= x) {
            l++;

            last = 1;
        }
        else if (a[i] < x && b[i] < x) {
            if (last != 0) {
                s++;
            }

            last = 0;
        }
    }

    return l > s;
}

void solve()
{
    int n, l, r, m, x = 1;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    l = 1, r = 2 * n;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(m, n, a, b)) {
            x = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << x << "\n";
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