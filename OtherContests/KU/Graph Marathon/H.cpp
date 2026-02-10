#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v, f = 1, node = 1;

    cin >> n >> m;

    vector <int> degree(n + 1, 0);
    vector <vector <int> > adj_list(n + 1);
    deque <int> dq, p(n, 0);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        degree[v]++;
        adj_list[u].push_back(v);
    }

    for (i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            dq.push_back(i);
        }
    }

    while (!dq.empty()) {
        if (dq.size() > 1) {
            f = 0;

            break;
        }
        else {
            u = dq.front();

            dq.pop_front();

            p[u - 1] = node++;

            for (auto &v : adj_list[u]) {
                degree[v]--;

                if (degree[v] == 0) {
                    dq.push_back(v);
                }
            }
        }
    }

    if (f) {
        cout << "Yes\n";

        for (auto &it : p) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}