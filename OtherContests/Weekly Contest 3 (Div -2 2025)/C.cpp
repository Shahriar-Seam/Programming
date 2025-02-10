#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, k;

    cin >> n >> m;

    vector <int> a(n + 1), b(m + 1, 0), c(n + m + 1);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : c) {
        cin >> it;
    }

    reverse(a.begin(), a.end());
    reverse(c.begin(), c.end());

    while (a.size() < m + 1) {
        a.push_back(0);
    }

    for (k = 0; k < m + 1; k++) {
        b[k] = c[k];

        for (i = k, j = 0; i > 0 && j < k; i--, j++) {
            b[k] -= a[i] * b[j];
        }

        b[k] /= a[0];
    }

    reverse(b.begin(), b.end());

    for (auto it : b) {
        cout << it << " ";
    }

    return 0;
}