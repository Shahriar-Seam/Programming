#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;
string s;
int cnt;

pair <int, int> dfs(int u)
{
    visited[u] = true;

    // b -> first, w -> second
    pair <int, int> p = {0, 0}, q;

    if (s[u - 1] == 'B') {
        p.first++;
    }
    else {
        p.second++;
    }

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            q = dfs(v);

            p.first += q.first;
            p.second += q.second;
        }
    }

    if (p.first == p.second) {
        cnt++;
    }

    return p;
}

void solve()
{
    int n, u, v;

    cin >> n;

    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, false);
    cnt = 0;

    for (v = 2; v <= n; v++) {
        cin >> u;

        adj_list[u].push_back(v);
    }

    cin >> s;

    dfs(1);

    cout << cnt << "\n";
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