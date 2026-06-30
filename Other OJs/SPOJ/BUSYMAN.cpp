#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, end = 0, count = 0;

    cin >> n;

    vector <pair <int, int> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        if (a.second == b.second) {
            return a.first > b.second;
        }
        else {
            return a.second < b.second;
        }
    });

    for (auto &it : v) {
        if (it.first >= end) {
            end = it.second;

            count++;
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