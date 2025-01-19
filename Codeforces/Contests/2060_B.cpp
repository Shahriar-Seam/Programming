#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j, temp, f = 1;

    cin >> n >> m;
    
    vector <pair <vector <int>, int> > v(n), temp_v;
    vector <int> p;
    vector <int> order;

    for (i = 0; i < n; i++) {
        v[i].second = i;

        for (j = 0; j < m; j++) {
            cin >> temp;

            v[i].first.push_back(temp);
        }

        sort(v[i].first.begin(), v[i].first.end());
    }

    temp_v = v;

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        p.push_back(v[i].second);
    }

    for (j = 0; j < m; j++) {
        for (i = 0; i < n; i++) {
            order.push_back(temp_v[p[i]].first[j]);
        }
    }

    if (is_sorted(order.begin(), order.end())) {
        for (auto it : p) {
            cout << it + 1 << " ";
        }
    }
    else {
        cout << -1;
    }

    cout << "\n";
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