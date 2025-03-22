#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (v[0] == 0 && v[n - 1] == 0) {
        cout << 3 << "\n";

        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << n - 1 << "\n";

        cout << 1 << " " << 2 << "\n";
    }
    else if (count(v.begin(), v.end(), 0) == 0) {
        cout << 1 << "\n";

        cout << 1 << " " << n << "\n";
    }
    else if (v[0] == 0) {
        cout << 2 << "\n";

        cout << 1 << " " << n - 1 << "\n";
        cout << 1 << " " << 2 << "\n";
    }
    else if (v[n - 1] == 0) {
        cout << 2 << "\n";

        cout << 2 << " " << n << "\n";
        cout << 1 << " " << 2 << "\n";
    }
    else {
        cout << 2 << "\n";

        cout << 1 << " " << n - 1 << "\n";
        cout << 1 << " " << 2 << "\n";
    }
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