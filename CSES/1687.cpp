#include <bits/stdc++.h>

using namespace std;

const int sz = 20;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, p, x, k;

    cin >> n >> q;

    vector <int> parent(n + 1, -1);
    vector <vector <int> > boss(n + 1, vector <int> (sz, -1));

    for (i = 2; i <= n; i++) {
        cin >> p;

        parent[i] = p;
    }

    for (i = 0; i < sz; i++) {
        for (p = 2; p <= n; p++) {
            if (i == 0) {
                boss[p][0] = parent[p];
            }
            else if (boss[p][i - 1] >= 0) {
                boss[p][i] = boss[boss[p][i - 1]][i - 1];
            }
        }
    }

    while (q--) {
        cin >> x >> k;

        for (i = 0; i < sz; i++) {
            if ((k & (1 << i)) && (x >= 0)) {
                x = boss[x][i];
            }
        }

        cout << x << "\n";
    }

    return 0;
}