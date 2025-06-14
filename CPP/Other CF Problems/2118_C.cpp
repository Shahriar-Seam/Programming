#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, beauty = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        beauty += __builtin_popcount(it);
    }

    for (i = 0; i < 63; i++) {
        for (auto &it : v) {
            if (!(it & (1LL << i))) {
                if (k >= (1LL << i)) {
                    beauty++;

                    k -= (1LL << i);
                }
            }
        }
    }

    cout << beauty << "\n";
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