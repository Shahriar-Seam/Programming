#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, count = 1e9;

    cin >> n >> k;

    vector <int> v(n);
    vector <vector <int> > pos(k + 1, vector <int> ());
    vector <priority_queue <int> > dist(k + 1, priority_queue <int> ());

    for (i = 0; i < n; i++) {
        cin >> v[i];

        pos[v[i]].push_back(i);
    }

    for (j = 1; j <= k; j++) {
        if (pos[j].empty()) {
            continue;
        }

        dist[j].push(pos[j][0]);
        dist[j].push(n - 1 - pos[j].back());

        for (i = 1; i < pos[j].size(); i++) {
            dist[j].push(pos[j][i] - pos[j][i - 1] - 1);
        }
    }

    for (j = 1; j <= k; j++) {
        if (dist[j].empty()) {
            continue;
        }

        auto temp = dist[j].top();

        dist[j].pop();

        dist[j].push(temp / 2);
    }

    for (j = 1; j <= k; j++) {
        if (dist[j].empty()) {
            continue;
        }
        
        count = min(count, dist[j].top());
    }

    cout << count << "\n";
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