#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, sum = 0, count = 0, i;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        sum += it;
    }

    sort(v.begin(), v.end());

    for (i = n - 1; i >= 0; i--) {
        while (i >= 0 && sum > x) {
            sum -= v[i];

            i--;
        }

        if (i >= 0) {
            count += 1 + (x - sum) / (i + 1);

            sum -= v[i];
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