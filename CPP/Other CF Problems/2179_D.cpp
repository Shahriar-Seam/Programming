#include <bits/stdc++.h>

using namespace std;

int suffix(int n)
{
    int i, count = 0;

    for (i = 0; i < 20; i++) {
        if (n & (1 << i)) {
            count++;
        }
        else {
            break;
        }
    }

    return count;
}

void solve()
{
    int n, i;

    cin >> n;

    vector <vector <int> > v(n + 1, vector <int> ());

    n = 1 << n;

    for (i = 0; i < n; i++) {
        v[suffix(i)].push_back(i);
    }

    for (i = v.size() - 1; i >= 0; i--) {
        for (auto &it : v[i]) {
            cout << it << " ";
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