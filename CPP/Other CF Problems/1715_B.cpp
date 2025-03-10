#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, b, s, i, temp;

    cin >> n >> k >> b >> s;

    vector <int> v(n);

    
    if (s >= k * b && s <= k * b + (k - 1) * n) {
        v[0] = k * b;
        s -= k * b;

        for (i = 0; i < n; i++) {
            temp = min(k - 1, s);
            s -= temp;
            v[i] += temp;
        }

        for (auto it : v) {
            cout << it << " ";
        }
    }
    else {
        cout << "-1";
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