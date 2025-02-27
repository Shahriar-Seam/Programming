#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, max_d = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> m;

    sort(v.begin(), v.end());

    for (i = 0; i < m; i++) {
        max_d = max(max_d, 2 * v[i]);
    }

    for (i; i < n; i++) {
        max_d = max(max_d, v[i]);
    }

    cout << max_d << "\n";

    return 0;
}