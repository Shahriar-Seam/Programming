#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, m, i, count = 0, cost = 0;

    cin >> a >> b >> c >> m;

    vector <pair <int, string> > v(m);
    vector <bool> taken(m, false);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < m; i++) {
        if (v[i].second == "USB" && a > 0) {
            a--;

            count++;

            cost += v[i].first;

            taken[i] = true;
        }

        if (v[i].second == "PS/2" && b > 0) {
            b--;

            count++;

            cost += v[i].first;

            taken[i] = true;
        }
    }

    for (i = 0; (i < m) && (c > 0); i++) {
        if (!taken[i]) {
            count++;

            cost += v[i].first;

            c--;
        }
    }

    cout << count << " " << cost << "\n";

    return 0;
}