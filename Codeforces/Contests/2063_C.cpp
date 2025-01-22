#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, u, v;
    int max_edges = 0, count = 0;

    cin >> n;

    vector <set <int> > g(n + 1);
    vector <pair <int, int> > degree;

    for (i = 0; i < n - 1; i++) {
        cin >> u >> v;

        g[u].insert(v);
        g[v].insert(u);
    }

    for (i = 1; i <= n; i++) {
        degree.push_back({g[i].size(), i});
    }

    sort(degree.begin(), degree.end(), greater <pair <int, int> > ());

    int max_degree = degree[0].first;
    int mcc = degree[0].first + degree[1].first;

    if (g[degree[0].second].find(degree[1].second) == g[degree[0].second].end()) {
        mcc--;
    }
    else {
        mcc -= 2;
    }

    for (i = 0; i < degree.size(); i++) {
        for (j = i + 1; j < (int) degree.size() && degree[j].first >= degree[i].first - 10000; j++) {
            if (g[degree[i].second].find(degree[j].second) == g[degree[i].second].end()) {
                mcc = max(mcc, degree[i].first + degree[j].first - 1);
            }
            else {
                mcc = max(mcc, degree[i].first + degree[j].first - 2);
            }
        }
    }

    cout << mcc << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}