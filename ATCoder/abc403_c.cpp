#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    int op, x, y;

    cin >> n >> m >> q;

    vector <set <int> > v(n + 1);

    while (q--) {
        cin >> op;

        if (op == 1) {
            cin >> x >> y;

            v[x].insert(y);
        }
        else if (op == 2) {
            cin >> x;

            v[x].clear();

            v[x].insert(-1);
        }
        else {
            cin >> x >> y;

            if (*v[x].begin() == -1) {
                cout << "Yes\n";
            }
            else if (v[x].find(y) != v[x].end()) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }

    return 0;
}