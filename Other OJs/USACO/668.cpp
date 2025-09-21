#include <bits/stdc++.h>

using namespace std;

#define int long long

int sq(int n)
{
    return n * n;
}

struct cow {
    int x, y, p;

    int dist(cow c) {
        return sq(x - c.x) + sq(y - c.y);
    }
};

int dfs(vector <vector <int> > &adj_list, vector <bool> &visited, int u)
{
    visited[u] = true;
    int count = 1;

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            count += dfs(adj_list, visited, v);
        }
    }

    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("moocast.in");
    ofstream cout("moocast.out");

    int n, i, j, max_cow = 1;

    cin >> n;

    vector <cow> v(n);
    vector <vector <int> > adj_list(n);

    for (auto &it : v) {
        cin >> it.x >> it.y >> it.p;

        it.p = sq(it.p);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                if (v[i].dist(v[j]) <= v[i].p) {
                    adj_list[i].push_back(j);
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        vector <bool> visited(n, false);
        max_cow = max(max_cow, dfs(adj_list, visited, i));
    }

    cout << max_cow << "\n";

    return 0;
}