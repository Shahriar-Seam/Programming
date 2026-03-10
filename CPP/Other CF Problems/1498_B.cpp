#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, w, h, i, f = 0, temp;
    map <int, int> mp;

    cin >> n >> w;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (h = 0; n; h++) {
        temp = w;

        for (i = 30; i >= 0; i--) {
            while ((1 << i) <= temp && mp[(1 << i)] > 0) {
                temp -= (1 << i);
                mp[(1 << i)]--;

                n--;
            }
        }
    }

    cout << h << "\n";
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