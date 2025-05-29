#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, i, j, f = 0;

    cin >> n >> m;

    vector <vector <int> > v(n, vector <int> (m));
    vector <vector <bool> > marked(n, vector <bool> (m, false));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    cin >> x;

    if (v[0][m - 1] != -1) {
        marked[0][m - 1] = true;
    }

    for (j = m - 2; j >= 0; j--) {
        if (marked[0][j + 1] && v[0][j] != -1) {
            marked[0][j] = true;
        }
        else {
            break;
        }
    }

    for (i = 1; i < n; i++) {
        if (marked[i - 1][m - 1] && v[i][m - 1] != -1) {
            marked[i][m - 1] = true;
        }
        else {
            break;
        }
    }

    for (i = 1; i < n; i++) {
        for (j = m - 2; j >= 0; j--) {
            if ((marked[i - 1][j] || marked[i][j + 1]) && v[i][j] != -1) {
                marked[i][j] = true;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == x && marked[i][j]) {
                f = 1;
            }
        }
    }

    cout << (f ? "YES" : "NO") << "\n";

    return 0;
}