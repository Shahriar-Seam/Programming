#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, i;
    int one = 0, two = 0, many = 0;

    cin >> n >> m;

    vector <int> degree(n + 1, 0);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        degree[u]++;
        degree[v]++;
    }

    for (i = 1; i <= n; i++) {
        one += (degree[i] == 1);
        two += (degree[i] == 2);
        many += (degree[i] > 1);
    }

    if (one == 2 && two == n - 2) {
        cout << "bus topology\n";
    }
    else if (two == n) {
        cout << "ring topology\n";
    }
    else if (one == n - 1 && many == 1) {
        cout << "star topology\n";
    }
    else {
        cout << "unknown topology\n";
    }

    return 0;
}