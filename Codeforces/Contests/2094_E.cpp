#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, sum = 0, max_sum = 0, f = 0;

    cin >> n;

    vector <int> v(n), counter(31, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        for (i = 0; i < 31; i++) {
            if (it & (1LL << i)) {
                counter[i]++;
            }
        }
    }

    for (i = 30; i >= 0; i--) {
        if (!f && counter[i] > 0) {
            f = 1;

            sum += (1LL << i) * (n - counter[i]);
        }
        else if (f && counter[i] > 0) {
            sum += (1LL << i);
        }
    }

    for (auto it : v) {
        sum = 0;
        
        for (i = 0; i < 31; i++) {
            if (it & (1LL << i)) {
                sum += (1LL << i) * (n - counter[i]);
            }
            else {
                sum += (1LL << i) * counter[i];
            }
        }

        max_sum = max(max_sum, sum);
    }

    cout << max_sum << "\n";
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