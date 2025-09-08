#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int k, x, c, v;
    vector <int> steps;

    cin >> k >> x;

    k = 1LL << (k + 1);

    c = x;
    v = k - x;

    while (c != v) {
        if (c < v) {
            v -= c;
            c *= 2;

            steps.push_back(1);
        }
        else {
            c -= v;
            v *= 2;

            steps.push_back(2);
        }
    }

    reverse(steps.begin(), steps.end());

    cout << steps.size() << "\n";

    for (auto &it : steps) {
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