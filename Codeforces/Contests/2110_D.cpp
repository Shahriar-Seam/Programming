#include <bits/stdc++.h>

using namespace std;

#define int long long

const long long inf = 2e16;

typedef pair <int, pair <int, long long> > item;

// int dijkstra(int n, int *b, vector <vector <pair <int, int> > > &adj_list)
// {
//     // {cost, {dest, batteries}}
//     priority_queue <item, vector <item>, greater <> > s;
//     vector <int> visited(n + 1, 0);

//     s.push({0, {1, 0LL}});

//     while (!s.empty()) {
//         auto p = s.top();
//         s.pop();

//         visited[p.second.first]++;

//         if (p.second.first == n) {
//             return p.first;
//         }

//         for (auto t : adj_list[p.second.first]) {
//             if (visited[t.first] < 50 && 1LL * p.second.second + b[p.second.first] >= 1LL * t.second) {
//                 s.push({max(p.first, t.second), {t.first, 1LL * p.second.second + b[p.second.first]}});
//             }
//         }
//     }

//     return -1;
// }

int dijkstra(int n, int *b, vector <vector <pair <int, int> > > &adj_list)
{
    // {max_edge_cost, dest}
    set <pair <int, int> > s;
    // {max_edge_cost, batteries}
    vector <pair <int, long long> > cost(n + 1, {inf, inf});

    s.insert({0, 1});
    cost[1] = {0, 0};

    while (!s.empty()) {
        auto p = *s.begin();
        s.erase(s.begin());

        int src = p.second;
        int max_edge_cost = p.first;

        if (src == n) {
            return max_edge_cost;
        }

        for (auto t : adj_list[src]) {
            int dest = t.first;
            int edge_cost = t.second;

            if (cost[dest].first > max(max_edge_cost, edge_cost) && cost[src].second + b[src] >= edge_cost) {
                auto it = s.find({cost[dest].first, dest});

                if (it != s.end()) {
                    s.erase(it);
                }

                cost[dest].first = max(max_edge_cost, edge_cost);
                cost[dest].second = cost[src].second + b[src];

                s.insert({max(max_edge_cost, edge_cost), dest});

                cout << dest << " ";
            }
        }
    }

    return -1;
}

void dfs(int u, vector <vector <pair <int, int> > > &adj_list, vector <bool> &visited, vector <int> &req)
{
    visited[u] = true;

    for (auto v : adj_list[u]) {
        if (!visited[v.first]) {
            req[v.first] = min(req[v.first], )
            dfs(v);
        }
    }
}

void solve()
{
    int n, m, s, t, c, i;

    cin >> n >> m;

    int b[n + 1];
    vector <vector <pair <int, int> > > adj_list(n + 1), adj_list2(n + 1);
    vector <int> req(n + 1, inf);
    vector <bool> visited(n + 1, false);

    for (i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (i = 0; i < m; i++) {
        cin >> s >> t >> c;

        adj_list[s].push_back({t, c});
        adj_list2[t].push_back({s, c});
    }

    cout << dijkstra(n, b, adj_list) << "\n";

    adj_list.clear();
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