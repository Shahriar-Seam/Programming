#include <bits/stdc++.h>

using namespace std;

vector <int> _2 = {1, 2, 1, 2, 2, 1, 1, 2};
vector <int> _3 = {1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3};

void solve()
{
    int n, i = 0;

    cin >> n;

    if (n & 1) {
        for (auto &it : _3) {
            cout << it << " ";
        }

        i = 3;
    }

    for (i; i < n - 1; i += 2) {
        for (auto &it : _2) {
            cout << it + i << " ";
        }
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