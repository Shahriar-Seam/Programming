// Wrong intuition

#include <bits/stdc++.h>

using namespace std;

#define int long long

struct item {
    int bought, neg;
};

item possible(vector <int> &a, vector <int> &b, int p)
{
    int i, neg = 0, bought = 0;

    for (i = 0; i < a.size(); i++) {
        if (p <= b[i]) {
            bought++;
        }
        if (p > a[i] && p <= b[i]) {
            neg++;
        }
    }

    return {bought, bought > 0 ? neg : LONG_LONG_MAX};
}

void solve()
{
    int n, k;
    int max_price = 0, max_earning = 0;
    int i, l, r, m, m1, m2;

    cin >> n >> k;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0, l = 0, r = 2e9 + 5; i < 50; i++) {
        m = (l + r) / 2;

        if (possible(a, b, m).neg <= k) {
            max_price = max(max_price, m);

            l = m;
        }
        else {
            r = m;
        }
    }

    // cout << max_price << "\n";

    for (i = 0, l = 0, r = max_price; i < 50; i++) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;

        auto bought1 = possible(a, b, m1).bought;
        auto bought2 = possible(a, b, m2).bought;

        if (bought1 * m1 < bought2 * m2) {
            l = m1;
        }
        else {
            r = m2;
        }
    }

    // cout << possible(a, b, l).bought << "\n";

    for (i = 0; i <= max_price; i++) {
        cout << possible(a, b, i).bought * i << " ";
    }

    cout << "\n";
}

int32_t main()
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