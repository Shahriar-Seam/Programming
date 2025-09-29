#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, i;
    set <int> s;

    cin >> n >> m;

    for (i = 1; i <= n; i++) {
        s.insert(i);
    }

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        s.erase(u);
        s.erase(v);
    }

    u = *s.begin();

    cout << n - 1 << "\n";
    
    for (v = 1; v <= n; v++) {
        if (u != v) {
            cout << u << " " << v << "\n";
        }
    }

    return 0;
}