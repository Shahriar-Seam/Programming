#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i = 0;
    set <int> s;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        s.insert(it);
    }

    for (auto &it : s) {
        if (i != it) {
            break;
        }

        i++;
    }

    cout << i << "\n";
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