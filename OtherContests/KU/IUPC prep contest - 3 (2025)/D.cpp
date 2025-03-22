#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, u, v;
    long long sum = 0LL;
    
    cin >> n;

    vector <int> vertices(n);
    vector <vector <int> > adj_list(n + 1);
    vector <pair <int, int> > mp;

    for (auto &it : vertices) {
        cin >> it;

        sum += it;
    }

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        if (adj_list[i].size() > 1) {
            mp.push_back({vertices[i - 1], adj_list[i].size() - 1});
        }
    }

    sort(mp.begin(), mp.end(), greater <pair <int, int> > ());

    cout << sum << " ";

    for (i = 2, j = 0; i < n; j++) {
        pair <int, int> p = mp[j];

        while (p.second--) {
            sum += p.first;
            i++;

            cout << sum << " ";
        }
    }

    cout << "\n";
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