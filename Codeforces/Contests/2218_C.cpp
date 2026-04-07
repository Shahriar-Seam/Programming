#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, a, b;

    cin >> n;

    a = 3 * n;
    b = 1;

    vector <int> v;

    for (i = 0; i < n; i++) {
        v.push_back(a--);
        v.push_back(a--);
        v.push_back(b++);
    }

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}