#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, count = 0, i, curr_gcd = 0, items = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        curr_gcd = __gcd(curr_gcd, v[i]);
        items++;

        if (v[i] == k) {
            count++;
        }

        if (curr_gcd == k) {
            count += items - 1;
        }
        else if (curr_gcd % k != 0) {
            curr_gcd = v[i];

            items = 1;
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