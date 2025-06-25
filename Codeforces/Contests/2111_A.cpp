#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, count = 0;
    vector <int> v = {0, 0, 0};

    cin >> x;

    while (v[0] < x) {
        v[0] = 2 * v[1] + 1;

        sort(v.begin(), v.end());

        count++;
    }

    cout << count << "\n";
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