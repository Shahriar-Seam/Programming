#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, c, d, a = INT_MAX, temp, i, j;
    vector <int> v, v_generated;

    cin >> n >> c >> d;

    int matrix[n][n];

    for (i = 0; i < n * n; i++) {
        cin >> temp;

        v.push_back(temp);

        a = min(a, temp);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                matrix[i][j] = a;
            }
            else if (j == 0) {
                matrix[i][j] = matrix[i - 1][j] + c;
            }
            else {
                matrix[i][j] = matrix[i][j - 1] + d;
            }

            v_generated.push_back(matrix[i][j]);
        }
    }

    sort(v.begin(), v.end());
    sort(v_generated.begin(), v_generated.end());

    puts(v == v_generated ? "YES" : "NO");
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