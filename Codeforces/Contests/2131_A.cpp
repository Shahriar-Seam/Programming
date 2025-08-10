#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, count = 1;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            count += a[i] - b[i];
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