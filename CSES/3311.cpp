#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i + j) & 1) {
                v[i][j] = v[i][j] == 'B' ? 'D' : 'B';
            }
            else {
                v[i][j] = v[i][j] == 'A' ? 'C' : 'A';
            }
        }

        cout << v[i] << "\n";
    }

    return 0;
}