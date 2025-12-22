#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, p = 1;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (n > m) {
        cout << 0 << "\n";
    }
    else {
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                p = (p * abs(v[i] - v[j])) % m;
            }
        }

        cout << p << "\n";
    }

    return 0;
}