#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j, l, r, u, d, sum = 0, max_sum = INT_MIN;
    vector <vector <int> > v(6, vector <int> (6));
    
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            cin >> v[i][j];
        }
    }

    for (u = 0; u < 4; u++) {
        for (l = 0; l < 4; l++) {
            sum = 0;

            sum += v[u][l] + v[u][l + 1] + v[u][l + 2];
            sum += v[u + 1][l + 1];
            sum += v[u + 2][l] + v[u + 2][l + 1] + v[u + 2][l + 2];

            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum;

    return 0;
}