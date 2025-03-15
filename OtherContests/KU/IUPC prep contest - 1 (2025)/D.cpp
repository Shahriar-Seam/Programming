#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, score = 0;
vector <int> a;
vector <vector <int> > adj_list;
vector <bool> visited;
map <int, int> mp;
set <int> missing;

int mex()
{
    return *missing.begin();
}

void dfs(int u)
{
    visited[u] = true;
    mp[a[u]]++;
    if (missing.find(a[u]) != missing.end()) {
        missing.erase(a[u]);
    }

    score = max(score, mex());

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    mp[a[u]]--;

    if (mp[a[u]] == 0) {
        missing.insert(a[u]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, u, v;

    cin >> n;

    a.resize(n + 1, -1);
    adj_list.resize(n + 1);
    visited.assign(n + 1, false);

    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 0; i <= n; i++) {
        missing.insert(i);
    }

    dfs(1);

    cout << score << "\n";

    return 0;
}