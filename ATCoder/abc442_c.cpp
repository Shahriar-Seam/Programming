#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, a, b, c;

    cin >> n >> m;

    vector <vector <int> > adj_list(n + 1);

    while (m--) {
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (i = 1; i <= n; i++) {
        c = n - adj_list[i].size() - 1;

        cout << (c * (c - 1) * (c - 2)) / 6 << " ";
    }

    return 0;
}