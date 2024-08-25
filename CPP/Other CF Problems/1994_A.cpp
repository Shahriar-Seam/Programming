#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j, temp;

    cin >> n >> m;

    vector <vector <int> > v(n, vector <int> (m));

    for (auto &it : v) {
        for (auto &it_i : it) {
            cin >> it_i;
        }
    }

    if (m == 1 && n == 1) {
        cout << -1 << "\n";

        return;
    }

    if (m > 1) {
        for (i = 0; i < n; i++) {
            temp = v[i].front();

            v[i].erase(v[i].begin());

            v[i].push_back(temp);
        }
    }
    else {
        auto it = v.front();

        v.erase(v.begin());

        v.push_back(it);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}