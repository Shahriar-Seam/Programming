#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, i, j, k, inf = 1e18;
    int a, b, c;

    cin >> n >> m >> q;

    vector <vector <int> > cost(n + 1, vector <int> (n + 1, inf));

    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;

        cost[a][b] = min(cost[a][b], c);
        cost[b][a] = min(cost[b][a], c);
    }

    for (i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cost[i][j] = cost[j][i] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    while (q--) {
        cin >> a >> b;

        cout << (cost[a][b] == inf ? -1 : cost[a][b]) << "\n";
    }

    return 0;
}