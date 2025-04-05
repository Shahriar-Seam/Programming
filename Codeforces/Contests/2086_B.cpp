#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, x, i, sum, full = 0, temp_sum = 0, cnt = 0;

    cin >> n >> k >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    reverse(v.begin(), v.end());

    sum = accumulate(v.begin(), v.end(), 0LL);

    full = (x - 1) / sum;

    if (full >= k) {
        cout << 0 << "\n";

        return;
    }

    int left_out = full * sum;

    temp_sum = left_out;

    for (i = 0; i < n; i++) {
        temp_sum += v[i];

        if (temp_sum >= x) {
            cnt = i;

            break;
        }
    }

    cout << n * k - full * n - cnt << "\n";
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