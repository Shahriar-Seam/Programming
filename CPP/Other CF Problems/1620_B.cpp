#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int w, h, k;

    cin >> w >> h;

    cin >> k;

    vector <int> y_0(k);

    for (auto &it : y_0) {
        cin >> it;
    }

    cin >> k;

    vector <int> y_h(k);

    for (auto &it : y_h) {
        cin >> it;
    }

    cin >> k;

    vector <int> x_0(k);

    for (auto &it : x_0) {
        cin >> it;
    }

    cin >> k;

    vector <int> x_h(k);

    for (auto &it : x_h) {
        cin >> it;
    }

    cout << max({h * (y_0.back() - y_0.front()), h * (y_h.back() - y_h.front()), w * (x_0.back() - x_0.front()), w * (x_h.back() - x_h.front())}) << "\n";
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