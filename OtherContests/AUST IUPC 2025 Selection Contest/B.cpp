#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, k, i, j, m, n;
    vector <vector <int> > v(31, vector <int> (31, 0));
    string s;

    v[1][1] = 2;

    for (i = 0; i < 31; i++) {
        v[i][0] = v[0][i] = 1;
    }

    for (i = 2; i < 31; i++) {
        v[1][i] = v[1][i - 1] + 1;
        v[i][1] = v[i - 1][1] + 1;
    }

    for (i = 2; i < 31; i++) {
        for (j = 2; j < 31; j++) {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }

    cin >> a >> b >> k;

    for (i = 0, m = a, n = b; i < a + b; i++) {
        if (m > 0 && k <= v[m - 1][n]) {
            s += 'a';

            m--;
        }
        else {
            s += 'b';

            k -= v[m][n] - v[m][n - 1];

            n--;
        }
    }

    cout << s << "\n";

    return 0;
}