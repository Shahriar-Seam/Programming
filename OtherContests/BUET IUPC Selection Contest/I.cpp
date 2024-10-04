#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, r, c;
    long long i, j, k = 1;

    cin >> n;

    r = n * 2 - 1;
    c = n;

    vector <vector <long long> > v(r, vector <long long> (c, 0));
    vector <vector <long long> > banana(r, vector <long long> (c, 0));

    for (i = 0; i < r / 2; i++) {
        for (j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    for (i; i < r; i++) {
        for (j = 0; j < r - i; j++) {
            cin >> v[i][j];
        }
    }

    banana[0][0] = v[0][0];

    for (i = 1; i <= r / 2; i++) {
        for (j = 0; j < c; j++) {
            banana[i][j] += v[i][j];

            if (j > 0) {
                banana[i][j] += max(banana[i - 1][j - 1], banana[i - 1][j]);
            }
            else {
                banana[i][j] += banana[i - 1][j];
            }
        }
    }
    for (i; i < r; i++) {
        for (j = 0; j < c; j++) {
            banana[i][j] += v[i][j];

            if (j < n - 1) {
                banana[i][j] += max(banana[i - 1][j + 1], banana[i - 1][j]);
            }
            else {
                banana[i][j] += banana[i - 1][j];
            }
        }
    }

    cout << banana[r - 1][0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}