#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k, i, x, y, l, r, d;

    cin >> n >> m >> k;

    vector <long long> v(n);
    vector <vector <long long> > ops(m, vector <long long> (3));
    vector <long long> diff(n + 1, 0);
    vector <long long> prefix(m + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < m; i++) {
        for (auto &it : ops[i]) {
            cin >> it;
        }
    }

    for (i = 0; i < k; i++) {
        cin >> x >> y;

        prefix[x - 1] += 1;
        prefix[y] -= 1;
    }

    for (i = 1; i <= m; i++) {
        prefix[i] += prefix[i - 1];
    }

    for (i = 0; i < m; i++) {
        l = ops[i][0];
        r = ops[i][1];
        d = ops[i][2];

        diff[l - 1] += (d * prefix[i]);
        diff[r] -= (d * prefix[i]);
    }

    for (i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
    }

    for (i = 0; i < n; i++) {
        cout << diff[i] + v[i] << " ";
    }

    return 0;
}