#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, m, count = 0;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            m = gcd(a[i], a[i + 1]);
        }
        else if (i == n - 1) {
            m = gcd(a[i - 1], a[i]);
        }
        else {
            m = lcm(gcd(a[i - 1], a[i]), gcd(a[i], a[i + 1]));
        }

        if (m < a[i]) {
            count++;
        }
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