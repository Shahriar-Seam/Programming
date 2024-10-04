#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    vector <string> s(n);
    vector <vector <long long> > path(n, vector <long long> (n, 0));

    for (auto &it : s) {
        cin >> it;
    }

    if (s[0][0] == '.') {
        path[0][0] = 1;
    }
    for (i = 1; i < n; i++) {
        if (s[i][0] == '*') {
            path[i][0] = 0;
        }
        else {
            path[i][0] = path[i - 1][0];
        }

        if (s[0][i] == '*') {
            path[0][i] = 0;
        }
        else {
            path[0][i] = path[0][i - 1];
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (s[i][j] == '*') {
                path[i][j] = 0;
            }
            else {
                path[i][j] = (path[i - 1][j] + path[i][j - 1]) % mod;
            }
        }
    }

    cout << path[n - 1][n - 1] << "\n";

    return 0;
}