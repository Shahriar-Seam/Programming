#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, k = 1000000000000000000;
    vector <int> v;

    cin >> n;

    for (i = 0; i < 18; i++) {
        if (n % (k + 1) == 0) {
            v.push_back(n / (k + 1));
        }

        k /= 10;
    }

    cout << v.size() << "\n";

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