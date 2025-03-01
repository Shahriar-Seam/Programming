#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 1, sum = 0;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <int> ());

    temp.push_back(v[0]);
    temp.push_back(v[n - 1]);

    for (i = 1; i < n - 1; i++) {
        temp.push_back(v[i]);
    }

    for (auto it : temp) {
        if (it == sum) {
            f = 0;

            break;
        }

        sum += it;
    }

    if (f) {
        cout << "YES\n";

        for (auto it : temp) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
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