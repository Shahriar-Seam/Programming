#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, len, max_len = 0;

    cin >> n;

    vector <int> v(n + 1);
    vector <vector <int> > adj_list(n + 1);

    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (i = 1; i <= n; i++) {
        adj_list[v[i]].push_back(i);
    }

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}