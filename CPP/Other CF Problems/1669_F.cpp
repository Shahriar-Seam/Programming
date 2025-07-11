#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, l, r, candies = 0;

    cin >> n;

    vector <int> v(n), p(n), s(n);

    for (auto &it : v) {
        cin >> it;
    }

    p[0] = v[0];
    s[n - 1] = v[n - 1];

    for (i = 1; i < n; i++) {
        p[i] = p[i - 1] + v[i];
    }

    for (i = n - 2; i >= 0; i--) {
        s[i] = s[i + 1] + v[i];
    }

    l = 0;
    r = n - 1;

    while (l < r) {
        if (p[l] == s[r]) {
            candies = l + 1 + n - r;
            
            l++;
        }
        else if (p[l] < s[r]) {
            l++;
        }
        else {
            r--;
        }
    }

    cout << candies << "\n";
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