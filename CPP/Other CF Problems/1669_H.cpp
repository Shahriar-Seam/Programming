#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, max_and = 0;

    cin >> n >> k;

    vector <int> v(n);
    vector <int> pop(32, 0);

    for (auto &it : v) {
        cin >> it;

        for (i = 30; i >= 0; i--) {
            if (it & (1LL << i)) {
                pop[i]++;
            }
        }
    }

    for (i = 30; i >= 0; i--) {
        if (n - pop[i] <= k) {
            k -= n - pop[i];
            pop[i] = n;
        }
    }

    for (i = 0; i < 31; i++) {
        if (pop[i] == n) {
            max_and |= (1LL << i);
        }
    }

    cout << max_and << "\n";
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