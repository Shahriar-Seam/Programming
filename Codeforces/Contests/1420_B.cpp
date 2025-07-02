#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, count = 0;

    cin >> n;

    vector <int> v(n), counter(32, 0);

    for (auto &it : v) {
        cin >> it;

        for (i = 0; i < 31; i++) {
            if (it & (1 << i)) {
                counter[i]++;
            }
        }
    }

    sort(v.begin(), v.end(), greater <int> ());

    for (auto &it : v) {
        for (i = 30; i >= 0; i--) {
            if (it & (1 << i)) {
                count += counter[i] - 1;

                break;
            }
        }

        for (i = 30; i >= 0; i--) {
            if (it & (1 << i)) {
                counter[i]--;
            }
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