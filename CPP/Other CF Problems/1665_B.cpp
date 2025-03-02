#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, equal_element = 0, max_count = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it: v) {
        cin >> it;
    }

    for (auto it: v) {
        mp[it]++;
    }

    for (auto it: mp) {
        if (it.second > max_count) {
            max_count = it.second;
            equal_element = it.first;            
        }
    }

    if (max_count == n) {
        cout << 0 << "\n";

        return;
    }

    int left = max_count, right = 0, ops = 0;

    if (max_count == 1) {
        ops = 2;
        
        left = 2;
    }

    while (left < n) {
        if (right > 0) {
            ops += min(right, n - left);

            left += right;

            right = 0;
        }
        else {
            right = left;

            ops++;
        }
    }

    cout << ops << "\n";
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