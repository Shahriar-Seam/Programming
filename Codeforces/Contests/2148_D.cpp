#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, sum = 0, i;

    cin >> n;

    vector <int> v(n), odd;

    for (auto &it : v) {
        cin >> it;

        if (it & 1) {
            odd.push_back(it);
        }
        else {
            sum += it;
        }
    }

    sort(odd.begin(), odd.end(), greater <> ());

    if (odd.empty()) {
        cout << 0 << "\n";
    }
    else {
        for (i = 0; i < (odd.size() + 1) / 2; i++) {
            sum += odd[i];
        }

        cout << sum << "\n";
    }
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