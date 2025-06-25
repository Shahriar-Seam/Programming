#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, count = 0;

    cin >> n;

    vector <pair <int, int> > p(n);
    map <pair <int, int>, int> e;

    for (auto &it : p) {
        cin >> it.first >> it.second;
    }

    sort(p.begin(), p.end());

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].first != p[j].first) {
                break;
            }
            else {
                e[{p[i].second, p[j].second}]++;
            }
        }
    }

    for (auto it : e) {
        count += (it.second * (it.second - 1)) / 2;
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
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}