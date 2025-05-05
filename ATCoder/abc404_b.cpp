#include <bits/stdc++.h>

using namespace std;

int num_ops(vector <string> &s, vector <string> &t, int n)
{
    int i, j, ops = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            ops += (s[i][j] != t[i][j]);
        }
    }

    return ops;
}

void rotate(vector <string> &s, int n)
{
    int i, j;

    vector <string> temp(n, string(n, '0'));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp[j][n - i - 1] = s[i][j];
        }
    }

    s = temp;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ops;
    
    cin >> n;

    vector <string> s(n), t(n);

    for (auto &it : s) {
        cin >> it;
    }

    for (auto &it : t) {
        cin >> it;
    }

    ops = num_ops(s, t, n);

    rotate(s, n);

    ops = min(ops, 1 + num_ops(s, t, n));

    rotate(s, n);

    ops = min(ops, 2 + num_ops(s, t, n));

    rotate(s, n);

    ops = min(ops, 3 + num_ops(s, t, n));

    cout << ops << "\n";

    return 0;
}