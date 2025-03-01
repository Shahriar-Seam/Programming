#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, u, v;

    cin >> n;

    vector <vector <int> > adj_mat(n, vector <int> (n, 0));

    for (i = 0; i < n; i++) {
        cin >> u >> k;

        for (j = 0; j < k; j++) {
            cin >> v;

            adj_mat[u - 1][v - 1] = 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << adj_mat[i][j];

            if (j != n - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}