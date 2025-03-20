#include <bits/stdc++.h>

using namespace std;

int bfs(vector <vector <int> > &adj_list, int root, int n)
{
    int u, v;
    queue <int> q;
    vector <int> height(n + 1, 0);

    q.push(root);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (auto v : adj_list[u]) {
            height[v] = height[u] + 1;

            q.push(v);
        }
    }

    return *max_element(height.begin(), height.end());
}

void solve()
{
    int n, i, r, c;

    cin >> n;

    vector <int> v(n);
    vector <vector <int> > adj_list(n + 1);
    queue <int> q;

    for (auto &it : v) {
        cin >> it;
    }

    adj_list[1].push_back(v[1]);
    r = 1;
    c = v[1];

    q.push(c);

    for (i = 2; i < n; i++) {
        if (v[i] > c) {
            c = v[i];

            adj_list[r].push_back(c);

            q.push(c);
        }
        else {
            if (!q.empty()) {
                r = q.front();

                q.pop();
            }
            else {
                r = c;
            }

            c = v[i];

            adj_list[r].push_back(c);
            q.push(c);
        }
    }

    cout << bfs(adj_list, 1, n) << "\n";
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