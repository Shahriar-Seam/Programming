#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, count = 0LL, rightmost = 0LL;

    cin >> n;

    vector <pair <int, int> > v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (i == 0) {
            count += v[i].second - v[i].first + 1;
        }
        else {
            if (rightmost > v[i].first) {
                if (rightmost < v[i].second) {
                    count += v[i].second - rightmost;
                }
            }
            else if (rightmost == v[i].first) {
                count += v[i].second - v[i].first;
            }
            else {
                count += v[i].second - v[i].first + 1;
            }
        }

        rightmost = max(rightmost, v[i].second);
    }

    cout << (long long) 1e9 - count << "\n";
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