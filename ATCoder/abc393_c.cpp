#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v, count = 0;

    cin >> n >> m;

    vector <set <int> > adj_list(n + 1, set <int> ());

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        if (u == v) {
            count++;
        }
        else if (adj_list[u].find(v) == adj_list[u].end()) {
            adj_list[u].insert(v);
            adj_list[v].insert(u);
        }
        else {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}