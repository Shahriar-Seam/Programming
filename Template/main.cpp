#include "headers.h"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e, u, v;

    cin >> n >> e;

    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, false);

    while (e--) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);

    return 0;
}