#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n), _2, _3, _6, _none;

    for (auto &it : v) {
        cin >> it;

        if (it % 6 == 0) {
            _6.push_back(it);
        }
        else if (it % 2 == 0) {
            _2.push_back(it);
        }
        else if (it % 3 == 0) {
            _3.push_back(it);
        }
        else {
            _none.push_back(it);
        }
    }

    for (auto &it : _6) {
        cout << it << " ";
    }

    for (auto &it : _2) {
        cout << it << " ";
    }

    for (auto &it : _none) {
        cout << it << " ";
    }

    for (auto &it : _3) {
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