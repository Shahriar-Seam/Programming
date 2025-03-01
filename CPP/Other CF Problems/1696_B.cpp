#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    temp.push_back(v[0] == 0 ? 0 : 1);

    for (i = 1; i < n; i++) {
        if (v[i] != 0 && temp.back() == 0) {
            temp.push_back(1);
        }
        else if (v[i] == 0 && temp.back() != 0) {
            temp.push_back(0);
        }
    }

    cout << min(2, (int) count(temp.begin(), temp.end(), 1)) << "\n";
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