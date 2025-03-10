#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;

    cin >> n >> k;

    vector <int> v(n), order;
    vector <pair <int, int> > temp;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v[i] %= k;
    }

    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            order.push_back(i + 1);
        }
        else {
            temp.push_back({v[i], -(i + 1)});
        }
    }
    
    sort(temp.begin(), temp.end(), greater <pair <int, int> > ());

    for (auto it : temp) {
        order.push_back(-it.second);
    }

    for (auto it : order) {
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