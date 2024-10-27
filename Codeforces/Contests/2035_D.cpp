#include <bits/stdc++.h>

using namespace std;

#define mod int(1e9 + 7)

void solve()
{
    int n, i;

    cin >> n;

    vector <long long> v(n), pref(n, 0), pref_again(n, 0);

    for (auto &it : v) {
        cin >> it;
    }

    pref[0] = v[0];
    pref_again[0] = 0;

    for (i = 1; i < n; i++) {
        while ((v[i - 1] % 2) == 0) {
            v[i] = v[i] * 2;
            v[i - 1] /= 2;
        }

        // v[i] %= mod;

        pref_again[i] += v[i - 1] + pref_again[i - 1];

        // cout << v[i - 1] << " " << pref_again[i] << "\n";

        pref_again[i] %= mod;

        pref[i] = pref_again[i] + v[i];

        pref[i] %= mod;
    }

    // for (auto it : v) {
    //     cout << it << " ";
    // }

    // cout << "\n";

    for (auto it : pref) {
        cout << it << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}